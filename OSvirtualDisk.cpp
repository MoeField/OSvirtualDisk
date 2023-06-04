// OSvirtualDisk.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DOS.h"

using namespace std;

int main() {
	DOS dos("test.vd");
	while (true) {
		cout << dos.fullPath() << "# " << flush;
		string tcmd;
		getline(cin, tcmd);
		vector<string> cmds;
		//遍历tcmd，分割命令，以空格为分隔符
		int i = 0;
		while (i < tcmd.length()) {
			string xcmd;
			while (i < tcmd.length() && tcmd[i] != ' ') {
				xcmd += tcmd[i];
				i++;
			}
			if (xcmd != "") {cmds.push_back(xcmd);}
			i++;
		}
		//判断命令，执行相应DOS操作
		if (cmds.size() == 0) { continue; }
		if (cmds[0] == "exit") { break; }
		else if (cmds[0] == "ls") { dos.ls(); }
		else if (cmds[0] == "cd") {
			if (cmds.size() == 2) { dos.cd(cmds[1]); }
			else { cout << "参数错误" << endl; }
		}
		else if (cmds[0] == "mkdir") {
			if (cmds.size() == 2) { dos.mkdir(cmds[1]); }
			else { cout << "参数错误" << endl; }
		}
		else if (cmds[0] == "rm") {
			if (cmds.size() == 2) { dos.rm(cmds[1]); }
			else { cout << "参数错误" << endl; }
		}
		else if (cmds[0] == "cls") { system("cls"); }
		else if (cmds[0] == "help") { dos.help(); }

		else if (cmds[0] == "cat") {
			if (cmds.size() == 2) { dos.cat_r(cmds[1]); }
			else if (cmds.size() == 3) {
				if (cmds[1] == ">") {
					vector<char> content;
					cout << "请输入文件内容，以回车结束" << endl;
					string line;
					getline(cin, line);
					for (int i = 0; i < line.length(); i++) {
						content.push_back(line[i]);
					}
					content.push_back('\n');

					dos.cat_w(cmds[2], content);
				}
				else if (cmds[1] == ">>") {
					vector<char> content;
					cout << "请输入增加的文件内容，以回车结束" << endl;
					string line;
					getline(cin, line);
					for (int i = 0; i < line.length(); i++) {
						content.push_back(line[i]);
					}
					content.push_back('\n');

					dos.cat_a(cmds[2], content);
				}
				else { cout << "参数错误" << endl; }
			}
			else { cout << "参数错误" << endl; }
		}
		else { cout << "命令错误" << endl; }
	}
	cout << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
