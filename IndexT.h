#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct IndexRec {//文件目录在目录块中的记录方式
public:
    IndexRec();
    IndexRec(long, const char*, char, long long);
    long fatherNum;//在文件树中的父节点编号
    char name[23];//文件名（含扩展名）长度在22Byte内
    char type;//type: Dir, File，Null
    long long fBlock;//文件第一个块的位置(块编号)，若为目录则无效（0）
};


class IndexNode {//文件目录在内存中的记录
public:
    char name[23];
    char type;//type: Dir, File
    long long fBlock;//文件第一个块的位置，若为目录则无效（0）
    vector<long> children;
     long father;

    IndexNode(const char* , char, long long,  long);
    
};

string fullPath(vector<IndexNode>& index, unsigned long curr);
int addChild(vector<IndexNode>&, IndexRec&);