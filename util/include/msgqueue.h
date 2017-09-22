//
// Created by linlongqing on 17-9-19.
//

#ifndef IMAGEPROCESSSERVER_MSGQUEUE_H
#define IMAGEPROCESSSERVER_MSGQUEUE_H
#include "ReceiveSocket.h"

typedef struct SMsgQueueNode
{
    int ipAddress;
    int portBase;
    SImageHeader imageHeader;
    void* pImageData;
    SMsgQueueNode* next;
} SMsgQueueNode;

class CMsgQueue
{
private:
    int maxSize;
    SMsgQueueNode queueHeader;
    SMsgQueueNode** pTail;
public:
    CMsgQueue();
    ~CMsgQueue();

    int PushFromTail(SMsgQueueNode* pNode);
    SMsgQueueNode* PopFromHeader();
};

int createMsgQueueNode(int ip, int portBase, SImageHeader* pImageHeader,
                       void* pImageData, SMsgQueueNode** pNodePointer);
void destroyMsgQueueNode(SMsgQueueNode** pNodePointer);

#endif //IMAGEPROCESSSERVER_MSGQUEUE_H
