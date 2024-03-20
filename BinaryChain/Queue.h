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
	QNode* ptail;//����һ��β�ڵ㣬������Ӳ���ֱ�Ӷ�λ��β�ڵ���������Ҫÿ�ζ�ѭ����������
	int size;//���浱ǰ������ЧԪ�ظ���������QueueSize��������ʱ�临�Ӷ�ΪO(N)
}Queue;

//���
void QueuePush(Queue* pqueue, QDataType data);
//����
void QueuePop(Queue* pqueue);
//��ʼ��
void QueueInit(Queue* pqueue);
//����
void QueueDestroy(Queue* pqueue);
//�п�
bool QueueEmpty(Queue* pqueue);
//��С
int QueueSize(Queue* pqueue);
//��ͷԪ��
QDataType QueueFront(Queue* pqueue);
//��βԪ��
QDataType QueueBack(Queue* pqueue);
