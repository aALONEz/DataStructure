#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "AddressBook.h"			//����ͨѶ¼ͷ�ļ�

#define LIST_MAX_SIZE 100			//��̬˳�����������ж��ٸ�Ԫ��

//typedef int SL_Data_Type;			//�ض���int������
typedef Contacts SL_Data_Type;		//����ϵ�˽ṹ�����Ͷ���ΪSL_Data_Type����ʱ˳��������ÿ��Ԫ�ض�����ϵ�˽ṹ��



//��̬˳���
typedef struct
{
	SL_Data_Type a[LIST_MAX_SIZE];	//��̬���뾲̬˳�������ռ�����
	int length;						//��̬˳�����Ч���ݸ���
}StaticSeqList;

//��̬˳���
typedef struct SeqList
{
	SL_Data_Type* a;				//��̬������ڴ�ָ��
	int length;						//��̬˳�����Ч���ݸ���
	int capacity;					//��̬˳����������
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