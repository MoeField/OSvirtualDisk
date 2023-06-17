#pragma once
const long blockNum = 65536;//64K×1024KB=64MB
const long blockSize = 1024;//1KB
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "IndexT.h"
#include "Block.h"

using namespace std;

class Vdisk {
public:
    fstream diskFile;
    char* blockStatus;//type: Dir, File£¬Null
    long long minAvailable;//最小可用块编号
public:
    Vdisk(Vdisk&& disk) noexcept;
    Vdisk(string fileName);
    ~Vdisk();

    Block readBlock(long long);
    int writeBlock(const Block&, long long);

    int clearBlocks(long long);

    vector<IndexNode> readIndex(long long fBlockNum = 0);
    int writeIndex(const vector<IndexNode>&, long long distBlockNum = 0);

    vector<char> readFile(long long);
    int writeFile(vector<char>&, long long);
};
