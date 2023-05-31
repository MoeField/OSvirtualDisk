#pragma once
class BlockHead
{
public:
    BlockHead();
    BlockHead(const BlockHead& _BH);
    BlockHead(
        char _status,
        long long _pre,
        long long _next,
        char _preType='\0'
    );
    //status[0] is used for block status:
    //status: Dirblock, Fileblock, Null
public:
    char status[8];
    long long preLL;
    long long nextLL;
};

