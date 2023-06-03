// OSvirtualDisk.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DOS.h"

using namespace std;

int main(){
    cout << "Hello World!\n";
    DOS dos("aa.vd");

    //*
    cout << endl << "try insert cat " <<endl;
    dos.mkdir("cat");
    cout << endl << "try insert add " << endl;
    dos.mkdir("add");
    cout << endl << "try insert add2 " << endl;
    dos.mkdir("add");
    cout << endl << "try insert bee " << endl;
    dos.mkdir("bee");
    cout << endl << "try insert bee2 " << endl;
    dos.mkdir("bee");
    cout << endl << "try insert cat2 " << endl;
    dos.mkdir("cat");
    dos.mkdir("a");
    dos.mkdir("b");
    dos.mkdir("c");
    dos.mkdir("d");
    dos.mkdir("e");
    dos.mkdir("f");
    dos.mkdir("g");
    dos.mkdir("h");
    dos.mkdir("i");
    dos.mkdir("j");
    dos.mkdir("k");
    dos.mkdir("l");
    dos.mkdir("m");
    dos.mkdir("n");
    dos.mkdir("o");
    dos.mkdir("p");
    dos.mkdir("q");
    dos.mkdir("r");
    dos.mkdir("s");
    dos.mkdir("t");
    dos.mkdir("u");
    dos.mkdir("v");
    dos.mkdir("w");
    dos.mkdir("x");
    dos.mkdir("y");
    dos.mkdir("z");

    for (char i = 'a'; i <= 'z'; i++) {
        char x[2] = { i };
        cout << "rm:" << string(x) << endl;
        dos.rm(string(x));
    }
    //*/

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
