#include "Queue.h"

/// <summary>
/// ����ʵ�ֶ��У����г�ʼ��������
/// </summary>
/// <param name="pqueue">Ҫ��ʼ���Ķ��У�Queue���͵Ľṹ��ָ��</param>
void QueueInit(Queue* pqueue)
{
	assert(pqueue);

	pqueue->phead = pqueue->ptail = NULL;
	pqueue->size = 0;
}

/// <summary>
/// ����ʵ�ֶ��У�������Ӻ�����
/// </summary>
/// <param name="pqueue">Ҫ��ӵ��Ǹ����У�Queue���͵Ľṹ��ָ��</param>
/// <param name="data">��ӵ����ݣ�QDataType���͵�ֵ</param>
void QueuePush(Queue* pqueue, QDataType data)
{
	assert(pqueue);

	//�½��ڵ�
	QNode* newQNode = (QNode*)malloc(sizeof(QNode));
	if (newQNode == NULL)
	{
		perror("QueuePush:malloc\n");
		exit(1);
	}
	newQNode->val = data;
	newQNode->next = NULL;
	//β��
	if (pqueue->ptail == NULL)
	{
		pqueue->phead = pqueue->ptail = newQNode;
	}
	else
	{
		pqueue->ptail->next = newQNode;
		pqueue->ptail = newQNode;
	}
	pqueue->size++;
}

/// <summary>
/// ����ʵ�ֶ��У����г��Ӻ�����
/// </summary>
/// <param name="pqueue">Ҫ���ӵĶ��У�Queue���͵Ľṹ��ָ��</param>
void QueuePop(Queue* pqueue)
{
	assert(pqueue);
	assert(pqueue->phead);//�����������Ҫ�����ݲſ��Ե���

	//ͷɾ
	if (pqueue->phead->next == NULL)//һ���ڵ�
	{
		free(pqueue->phead);
		pqueue->phead = pqueue->ptail = NULL;
	}
	else//����ڵ�
	{
		QNode* tmpQNode = pqueue->phead;
		pqueue->phead = pqueue->phead->next;
		//�ͷŽڵ�
		free(tmpQNode);
	}
	pqueue->size--;
}

/// <summary>
/// ����ʵ�ֶ��У��������ٺ�����
/// </summary>
/// <param name="pqueue">Ҫ���ٵĶ��У�Queue���͵Ľṹ��ָ��</param>
void QueueDestroy(Queue* pqueue)
{
	assert(pqueue);

	QNode* currQNode = pqueue->phead;
	while (currQNode)
	{
		QNode* delQNode = currQNode;
		currQNode = currQNode->next;
		free(delQNode);
	}
	pqueue->ptail = pqueue->phead = NULL;
	pqueue->size = 0;
}

/// <summary>
/// ����ʵ�ֶ��У������Ƿ�Ϊ�պ�����
/// </summary>
/// <param name="pqueue">Ҫ�鿴�Ķ��У�Queue���͵Ľṹ��ָ��</param>
/// <returns>Ϊ�շ��� true  ��Ϊ�շ���false</returns>
bool QueueEmpty(Queue* pqueue)
{
	assert(pqueue);

	return !(pqueue->phead);
}

/// <summary>
/// ����ʵ�ֶ��У��鿴������ЧԪ�ظ���������
/// </summary>
/// <param name="pqueue">Ҫ�鿴�Ǹ����У�Queue���͵Ľṹ��ָ��</param>
/// <returns></returns>
int QueueSize(Queue* pqueue)
{
	assert(pqueue);

	/*QNode* tmpQNode = pqueue->phead;
	int ret = 0;
	while (tmpQNode)
	{
		ret++;
		tmpQNode = tmpQNode->next;
	}
	return ret;*/

	return pqueue->size;
}

/// <summary>
/// ����ʵ�ֶ��У��鿴����ͷ��Ԫ�غ�����
/// </summary>
/// <param name="pqueue">Ҫ�鿴�Ǹ����У�Queue���͵Ľṹ��ָ��</param>
/// <returns>���ض���ͷ��Ԫ�ص�ֵ</returns>
QDataType QueueFront(Queue* pqueue)
{
	assert(pqueue);
	assert(pqueue->phead);//�����в�����û��Ԫ��

	return pqueue->phead->val;
}

/// <summary>
/// ����ʵ�ֶ��У��鿴����β��Ԫ�غ�����
/// </summary>
/// <param name="pqueue">Ҫ�鿴�Ǹ����У�Queue���͵Ľṹ��ָ��</param>
/// <returns>���ض���β��Ԫ�ص�ֵ</returns>
QDataType QueueBack(Queue* pqueue)
{
	assert(pqueue);
	assert(pqueue->phead);//�����в�����û��Ԫ��

	return pqueue->ptail->val;
}
