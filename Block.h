#pragma once
#include "BlockHead.h"

class Block
{
public:
    Block();
    Block(const BlockHead& _head);
    Block(const Block& _Block);
public:
    BlockHead head;
    char data[1000];
};

