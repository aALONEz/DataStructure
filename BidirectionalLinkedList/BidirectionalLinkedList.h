#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int BLL_DataType;

typedef struct BidirectionalLinkedList
{
	struct BidirectionalLinkedList* prev;
	BLL_DataType data;
	struct BidirectionalLinkedList* next;
}BLL_Node;

BLL_Node* BLL_Init(void);
void BLL_PushBack(BLL_Node* phead, BLL_DataType data);
void BLL_PushFront(BLL_Node* phead, BLL_DataType data);
void BLL_Print(BLL_Node* phead);
void BLL_PopBack(BLL_Node* phead);
void BLL_PopFront(BLL_Node* phead);
BLL_Node* BLL_Find(BLL_Node* phead, BLL_DataType data);
void BLL_Insert(BLL_Node* posNode, BLL_DataType data);
void BLL_Erase(BLL_Node* posNode);
//void BLL_DesTroy(BLL_Node** pphead);
void BLL_DesTroy(BLL_Node* phead);