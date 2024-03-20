#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef struct BTNode* QDataType;
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;//定义一个尾节点，方便入队操作直接定位到尾节点插入而不需要每次都循环遍历队列
	int size;//保存当前队列有效元素个数，避免QueueSize函数出现时间复杂度为O(N)
}Queue;

//入队
void QueuePush(Queue* pqueue, QDataType data);
//出队
void QueuePop(Queue* pqueue);
//初始化
void QueueInit(Queue* pqueue);
//销毁
void QueueDestroy(Queue* pqueue);
//判空
bool QueueEmpty(Queue* pqueue);
//大小
int QueueSize(Queue* pqueue);
//队头元素
QDataType QueueFront(Queue* pqueue);
//队尾元素
QDataType QueueBack(Queue* pqueue);
