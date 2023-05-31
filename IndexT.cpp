#include "IndexT.h"

//Index Record in ROM
IndexRec::IndexRec() :
    fatherNum(-1), name("\0"), type('N'), fBlock(-1) {}


IndexRec::IndexRec(long f, const char* n, char t, long long fbn) :
    fatherNum(f), name("\0"), type(t), fBlock(fbn) {
    //strcpy_s(name, 23, n);
    for (int i = 0; i < 22; i++) {
        name[i] = n[i];
        if (n[i] == '\0') { break; }
    }
    name[22] = '\0';
}


//Index treeNode in RAM
IndexNode::IndexNode(
    char* ne,//name
    char ty,//type
    long long fb,//if type is file, fb is first fileBlockNum
    IndexNode* fa//node father
) :name("\0"), type(ty), fBlock(fb), father(fa)
{   //copy ne to name
    for (int i = 0; i < 22; i++) {
        name[i] = ne[i];
        if (ne[i] == '\0') { break; }
    }
    //strcpy_s(name, 22, ne);
    name[22] = '\0';
}



int IndexNode::addChild(vector<IndexNode>& index, IndexRec& rec) {
    IndexNode temp(rec.name, rec.type, rec.fBlock, &index[rec.fatherNum]);
    index.push_back(temp);
    index[rec.fatherNum].children.push_back(&index[index.size() - 1]);

    return 0;
}

string IndexNode::fullPath() {
    string tmp = "/";
    IndexNode* pathPtr = this;
    while (pathPtr->father) {
        tmp = "/" + string(pathPtr->name) + tmp;
        pathPtr = pathPtr->father;
    }
    return tmp;
}