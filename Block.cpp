#include "Block.h"
#include <fstream>

Block::Block() : head(), data("\0") {}
Block::Block(const BlockHead& _head) : head(_head), data("\0") {}
Block::Block(const Block& _Block) : head(_Block.head)
{
    memcpy(
        (char*)this->data,
        _Block.data,
        sizeof(this->data)
    );
}