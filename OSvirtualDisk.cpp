// OSvirtualDisk.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DOS.h"

using namespace std;

int main(){
    cout << "Hello World!\n";
    DOS dos("aa.vd");


    for (char i = 'a'; i <= 'f'; i++) {
        char x[2] = { i };
        cout << "mkdir:" << string(x) << endl;
        dos.mkdir(string(x));
    }
    cout  << dos.fullPath() << "#" << endl;
    dos.ls();
    dos.cd("z");
    cout  << dos.fullPath() << "#" << endl;
    dos.cd("a");
    cout  << dos.fullPath() << "#" << endl;
    for (char i = 'h'; i <= 'n'; i++) {
        char x[2] = { i };
        cout << "mkdir:" << string(x) << endl;
        dos.mkdir(string(x));
    }
    cout  << dos.fullPath() << "#" << endl;
    dos.ls();
    dos.cd("..");
    cout  << dos.fullPath() << "#" << endl;
    dos.rm("z");
    dos.rm("a");
    /*
    //vector<char> v;
    //for (char i = 'a'; i <= 'z'; i++) {v.push_back(i);}
    //dos.cat_w("xec", v);
    dos.cat_r("xec");
    cout << endl;

    //for (char i = 'A'; i <= 'Z'; i++) { v.push_back(i);}
    //dos.cat_w("xec", v);
    //dos.cat_a("xec", v);
    //dos.cat_r("xec");

    system("pause");
    cout << endl << endl;
    */

    /*
    for (char i = 'a'; i <= 'z'; i++) {
        char x[2] = { i };
        cout << "rm:" << string(x) << endl;
        dos.rm(string(x));
    }
    */
    //system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
