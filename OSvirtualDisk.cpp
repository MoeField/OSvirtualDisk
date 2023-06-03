// OSvirtualDisk.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DOS.h"

using namespace std;

int main(){
    cout << "Hello World!\n";
    DOS dos("aa.vd");


    for (char i = 'a'; i <= 'z'; i++) {
        char x[2] = { i };
        cout << "mkdir:" << string(x) << endl;
        dos.mkdir(string(x));
    }
    dos.ls();
    /*
    for (char i = 'a'; i <= 'z'; i++) {
        char x[2] = { i };
        cout << "rm:" << string(x) << endl;
        dos.rm(string(x));
    }
    */

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
