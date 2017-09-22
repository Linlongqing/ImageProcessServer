//
// Created by lin on 17-9-19.
//

#include "msgqueue.h"
#include <stdlib.h>
#include <string.h>

CMsgQueue::CMsgQueue()
{
    pTail = &queueHeader.next;
    queueHeader.pImageData = NULL;
}

CMsgQueue::~CMsgQueue()
{
    SMsgQueueNode* pNode = &queueHeader;

    while(pNode->next != NULL)
    {
        SMsgQueueNode* tmp = pNode;
        pNode = pNode->next;
        destroyMsgQueueNode(&tmp);
    }
}

int createMsgQueueNode(int ip, int portBase, SImageHeader* pImageHeader,
                                  void* pImageData, SMsgQueueNode **pNodePointer)
{
    *pNodePointer = (SMsgQueueNode *)malloc(sizeof(SMsgQueueNode));
    (*pNodePointer)->ipAddress = ip;
    (*pNodePointer)->portBase = portBase;
    (*pNodePointer)->imageHeader = *pImageHeader;
    (*pNodePointer)->pImageData = (void *)malloc(pImageHeader->dataSize * sizeof(int));
    memcpy((*pNodePointer)->pImageData, pImageData, pImageHeader->dataSize * sizeof(int));
    (*pNodePointer)->next = NULL;
}

void destroyMsgQueueNode(SMsgQueueNode **pNodePointer)
{
    if((*pNodePointer) != NULL)
    {
        if((*pNodePointer)->pImageData != NULL)
        {
            free((*pNodePointer)->pImageData);
            (*pNodePointer)->pImageData = NULL;
        }

        free((*pNodePointer));
        (*pNodePointer) = NULL;
    }
}

int CMsgQueue::PushFromTail(SMsgQueueNode *pNode)
{
    *pTail = pNode;
    pTail = &pNode->next;
}

SMsgQueueNode* CMsgQueue::PopFromHeader()
{
    SMsgQueueNode* tmp;
    tmp = queueHeader.next;
    if(queueHeader.next != NULL)
    {
        queueHeader.next = queueHeader.next->next;
    }
    if(queueHeader.next == NULL)
    {
        pTail = &queueHeader.next;
    }

    return tmp;
}
