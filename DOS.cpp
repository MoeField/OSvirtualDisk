#include "DOS.h"

DOS::DOS(string fname):disk(fname) 
{
	diskDirList = disk.readIndex();//读取磁盘目录
	//如果磁盘目录为空，创建根目录
	if (diskDirList.empty()) {
		cout<<"No index file found, creating a new one..."<<endl;
		IndexNode root("", 'D', -1, nullptr);
		diskDirList.push_back(root);
		disk.writeIndex(diskDirList);
	}
	//打印目录

	curDir= &diskDirList[0];//当前目录指针，指向根目录
	//_curDir = diskDirList.begin();
	cout<<"Current directory: _"<<curDir->name<<"/" << endl;
}

DOS::~DOS() {
	disk.writeIndex(diskDirList);
}
//成员函数---------------------------------------------------------
int DOS::help(string command){
	//默认为""(空字符串)
	if (command == ""){
		cout<<"help: show all commands"<<endl;
		cout<<"ls: list all files and directories"<<endl;
		cout<<"cd: change directory"<<endl;
		cout<<"mkdir: make a new directory"<<endl;
		cout<<"rm: remove a file or directory"<<endl;
		cout<<"cat: create a new file"<<endl;
		cout<<"exit: exit the system"<<endl;
	}
//help ls
	else if(command == "ls"){
		cout<<"ls: list all files and directories"<<endl;
	}
//help cd
	else if(command == "cd"){
		cout<<"cd: change directory"<<endl;
	}
//help mkdir
	else if(command == "mkdir"){
		cout<<"mkdir: make a new directory"<<endl;
	}
//help rm
	else if(command == "rm"){
		cout<<"rm: remove a file or directory"<<endl;
	}
//help cat
	else if(command == "cat"){
		cout<<"cat: create, modify(append) or read a file"<<endl;
	}
//help exit
	else if(command == "exit"){
		cout<<"exit: exit the system"<<endl;
	}
	else{
		cout<<"No such command!"<<endl;
		return -1;
	}
	return 0;
};


int DOS::mkdir(string name) {
	//如果含有空格，报错
	 if (name.find(' ') != string::npos) {
		cout<<"Invalid name! Do not use space in name."<<endl;
		return -1;
	}
	
	//查找当前目录下是否存同名文件或目录
	for (long i = 0; i < curDir->children.size(); i++) {
		if (string(curDir->children[i]->name) == name) {
			cout<<"Same name file or directory exists!"<<endl;
			return -1;
		}
	}
	//创建新目录
	IndexNode newDir(name.c_str(), 'D', -1, curDir);
	diskDirList.push_back(newDir);
	if (!diskDirList.empty()) {
		//cout << curDir->children.size()<<" " << curDir->children.max_size() << endl;
		IndexNode* newDirP = &diskDirList.back();
		//(*curDir).children.push_back(newDirP);
		long curDirNo = 0;
		for (long i = 0; i < diskDirList.size(); i++) {
			if (diskDirList[i].father == curDir->father) {
				if (string(diskDirList[i].name) == string(curDir->name)) {
					curDirNo = i;
					break;
				}
			}
		}
		diskDirList[curDirNo].children.push_back(newDirP);
	}
	else {
		cerr<<"Error: diskDirList is empty!"<<endl;
		return -1;
	}

	cout<<"New directory created!"<<endl;
	//将更新后的目录写入磁盘

	disk.writeIndex(diskDirList);
	return 0;
}

int DOS::rm(string trashName) {
	//查找当前目录下是否存在该文件或目录
	IndexNode* trash = nullptr;
	bool exist = false;
	for(long i = 0;i<curDir->children.size();i++){
		if(curDir->children[i]->name == trashName){
			trash = curDir->children[i];
			exist=true;
			break;
		}
	}
	//
	if (!exist) {
		cout << "None file or directory named " << trash << endl;
		return -1; 
	}
	//记录所有需要递归删除的元素（广度优先）
	vector<IndexNode*> toDel;
	toDel.push_back(trash);
	IndexNode* rP = toDel[0];
	for (int i = 0; i < rP->children.size(); i++) {
		toDel.push_back(rP->children[i]);
	}
	while (rP != toDel.back()) {
		rP++;
		for (int i = 0; i < rP->children.size(); i++) {
			toDel.push_back(rP->children[i]);
		}
	}
	//执行删除
	while (!toDel.empty()) {
		auto dP = toDel.back();
		toDel.pop_back();
		//遍历磁盘目录(vector内存不一定连续，不能用直接寻址)
		for (long i = 0; i < diskDirList.size(); i++) {
			if (diskDirList[i].father != dP->father) { continue; }
			if (string(diskDirList[i].name) != string(dP->name)) { continue; }
			//元素删除列表中最后一位记录之后的所有元素的上层目录指针自减
			for (
				vector<IndexNode>::iterator itDec = diskDirList.end() - 1;
				itDec != diskDirList.begin() + i; itDec--) {
				itDec->father--;
			}
			//如果是文件，释放磁盘空间
			if (dP->type == 'F'&& dP->fBlock>0) {
				disk.clearBlocks(dP->fBlock);
			}
			diskDirList.erase(diskDirList.begin() + i);
			break;
		}
	}
	//将更新后的目录写入磁盘
	disk.writeIndex(diskDirList);
	return 0;
}

