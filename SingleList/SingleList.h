#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ListDataType;

typedef struct ListNode
{
    ListDataType data;
    struct ListNode *next;
}SingleListNode;

void SLPrintInt(void *data);
void SingleList_Print(SingleListNode *pSL_Node, void SLPrint(void *data));
void SingleList_PushBack(SingleListNode **ppSL_Node, ListDataType x);
void SingleList_PushFront(SingleListNode **ppSL_Node, ListDataType x);
void SingleList_PopBack(SingleListNode **ppSL_Node);
void SingleList_PopFront(SingleListNode **ppSL_Node);