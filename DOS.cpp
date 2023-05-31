#include "DOS.h"

DOS::DOS(string fname):disk(fname) 
{
	diskDirList=disk.readIndex();
	curDir= &diskDirList[0];
}

DOS::~DOS() {
	;
}


int DOS::del_r(IndexNode& trash) {
	//
	bool exist = false;
	for (vector<IndexNode>::iterator it = diskDirList.begin();
		it != diskDirList.end(); it++) {
		if (it->father == trash.father &&
			string(it->name) == string(trash.name)) {
			exist = true; break;
		}
	}
	if (!exist) { return -1; }
	//
	vector<IndexNode*> toDel;
	toDel.push_back(&trash);
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
	//
	while (!toDel.empty()) {
		auto dP = toDel.back();
		toDel.pop_back();
		for (long i = 0; i < diskDirList.size(); i++) {
			if (diskDirList[i].father != dP->father) { continue; }
			if (string(diskDirList[i].name) != string(dP->name)) { continue; }
			//
			for (
				vector<IndexNode>::iterator itDec = diskDirList.end() - 1;
				itDec != diskDirList.begin() + i; itDec--) {
				itDec->father--;
			}
			diskDirList.erase(diskDirList.begin() + i);
			break;
		}
	}
	return 0;
}