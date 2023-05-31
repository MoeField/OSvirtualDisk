#include "BlockHead.h"

BlockHead::BlockHead() :status{ 'N','N','\0'}, preLL(0), nextLL(0) {}

BlockHead::BlockHead(const BlockHead& _BH) :
    status{ 'N','N','\0' },
    preLL(_BH.preLL),
    nextLL(_BH.nextLL)
{for (int i = 0; i < 8; i++) { this->status[i] = _BH.status[i]; }}

BlockHead::BlockHead(
    char _status,
    long long _pre,
    long long _next,
    char _preType
) :status{ _status,_preType }, preLL(_pre), nextLL(_next) {}
