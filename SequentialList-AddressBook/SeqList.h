#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "AddressBook.h"			//包含通讯录头文件

#define LIST_MAX_SIZE 100			//静态顺序表的最大可以有多少个元素

//typedef int SL_Data_Type;			//重定义int类型名
typedef Contacts SL_Data_Type;		//将联系人结构体类型定义为SL_Data_Type，此时顺序表里面的每个元素都是联系人结构体



//静态顺序表
typedef struct
{
	SL_Data_Type a[LIST_MAX_SIZE];	//静态申请静态顺序表的最大空间容量
	int length;						//静态顺序表有效数据个数
}StaticSeqList;

//动态顺序表
typedef struct SeqList
{
	SL_Data_Type* a;				//动态申请的内存指针
	int length;						//动态顺序表有效数据个数
	int capacity;					//动态顺序表最大容量
}DynamicSeqList;


void DSL_Init(DynamicSeqList* pDSL);
void DSL_PushBack(DynamicSeqList* pDSL, SL_Data_Type x);
void DSL_PushFront(DynamicSeqList* pDSL, SL_Data_Type x);
void DSL_PopBack(DynamicSeqList* pDSL);
void DSL_PopFront(DynamicSeqList* pDSL);
void DSL_Insert(DynamicSeqList* pDSL, int pos, SL_Data_Type x);
void DSL_Erase(DynamicSeqList* pDSL, int pos);
int DSL_Find(DynamicSeqList* pDSL, SL_Data_Type x);
void DSL_DesTroy(DynamicSeqList *pDSL);
void DSL_Modify(DynamicSeqList* pDSL, int pos, SL_Data_Type x);