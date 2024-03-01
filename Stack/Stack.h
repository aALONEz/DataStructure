#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;//����ָ��
	int top;//ջ��Ԫ�ص��±�
	int capacity;//��С
}ST;

void ST_Init(ST* pstack);
void ST_Destroy(ST* pstack);
void ST_Push(ST* pstack, STDataType data);
void ST_Pop(ST* pstack);
STDataType ST_Top(ST* pstack);
int ST_Size(ST* pstack);
bool ST_Empty(ST* pstack);
