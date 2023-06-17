#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Vdisk.h"

using namespace std;


class DOS {
public:
    Vdisk disk;
    vector<IndexNode> diskDirList;//磁盘目录树
    //vector<IndexNode> ::iterator _curDir;
    long curDir;//当前文件指针(值为存储目录树的数组下标)
public:
    DOS(string fname="virtDisk.vd");
    ~DOS();

    string fullPath();
    int ls();
    int help(string command="");

    int cd(string);

    int mkdir(string);
    int rm(string);

    int cat_r(string);//read
    int cat_w(string, vector<char> & ); //write
    int cat_a(string, vector<char> & ); //append
};

