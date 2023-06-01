#include "IndexT.h"

//Index Record in ROM
IndexRec::IndexRec() :
    fatherNum(-1), name(""), type('N'), fBlock(-1) {}


IndexRec::IndexRec(long f, const char* n, char t, long long fbn) :
    fatherNum(f), name{ '\0' }, type(t), fBlock(fbn) {
    //strcpy_s(name, 23, n);
    for (int i = 0; i < 22; i++) {
        name[i] = n[i];
        if (n[i] < 32) { name[i] = '\0'; break; }
    }
    name[22] = '\0';
}


//Index treeNode in RAM
IndexNode::IndexNode(
    const char* ne,//name
    char ty,//type
    long long fb,//if type is file, fb is first fileBlockNum
    long fa//node father
) :name{ '\0' }, type(ty), fBlock(fb), father(fa)
{   //copy ne to name
    for (int i = 0; i < 22; i++) {
        name[i] = ne[i];
        if (ne[i] < 32) { name[i] = '\0'; break; }
    }
    //strcpy_s(name, 22, ne);
    name[22] = '\0';
}

string IndexNode::fullPath(vector<IndexNode>& index) {
    string tmp = "/" + string(this->name);
    long pathPtr = this->father;
    while (pathPtr >=0) {
        tmp = "/" + string(index.at(pathPtr).name) + tmp;
        pathPtr = index.at(pathPtr).father;
    }
    return tmp;
}

int addChild(vector<IndexNode>& index, IndexRec& rec) {
    IndexNode temp(
        rec.name,
        rec.type,
        rec.fBlock,
        rec.fatherNum
    );
    index.push_back(temp);
    if (rec.fatherNum >= 0) {
        index.at(rec.fatherNum).children.push_back(index.size() - 1);
    }
    return 0;
}
