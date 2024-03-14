#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* val;
	int size;
	int capacity;
}HP;

void HP_Init(HP* php);
void HP_Destroy(HP* php);
void HP_Push(HP* php, HPDataType val);
HPDataType HP_Top(HP* php);
void HP_Pop(HP* php);
bool HP_Empty(HP* php);
int HP_Size(HP* php);
void HP_InitArray(HP* php, HPDataType* arr, int size);
void HeapSort(int* a, int n);