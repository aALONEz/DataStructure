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
void SingleList_Print(SingleListNode** const ppSL_Node, void SLPrint(void *data));
void SingleList_PushBack(SingleListNode** const ppSL_Node, ListDataType x);
void SingleList_PushFront(SingleListNode** const ppSL_Node, ListDataType x);
void SingleList_PopBack(SingleListNode** const ppSL_Node);
void SingleList_PopFront(SingleListNode** const ppSL_Node);
SingleListNode* SingleList_Find(SingleListNode** const ppSL_Node, ListDataType x);
void SingleList_Insert(SingleListNode** const ppSL_Node, SingleListNode* const posSL_Node, ListDataType x);
void SingleList_InsertAfter(SingleListNode* posSL_Node, ListDataType x);
void SingleList_Erase(SingleListNode** const ppSL_Node, SingleListNode* posSL_Node);
void SingleList_EraseAfter(SingleListNode* posSL_Node);
void SingleList_DesTroy(SingleListNode** ppSL_Node);