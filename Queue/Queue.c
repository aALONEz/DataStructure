#include "Queue.h"

/// <summary>
/// 链表实现队列，队列初始化函数。
/// </summary>
/// <param name="pqueue">要初始化的队列，Queue类型的结构体指针</param>
void QueueInit(Queue* pqueue)
{
	assert(pqueue);

	pqueue->phead = pqueue->ptail = NULL;
	pqueue->size = 0;
}

/// <summary>
/// 链表实现队列，队列入队函数。
/// </summary>
/// <param name="pqueue">要入队到那个队列，Queue类型的结构体指针</param>
/// <param name="data">入队的数据，QDataType类型的值</param>
void QueuePush(Queue* pqueue, QDataType data)
{
	assert(pqueue);

	//新建节点
	QNode* newQNode = (QNode*)malloc(sizeof(QNode));
	if (newQNode == NULL)
	{
		perror("QueuePush:malloc\n");
		exit(1);
	}
	newQNode->val = data;
	newQNode->next = NULL;
	//尾插
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
/// 链表实现队列，队列出队函数。
/// </summary>
/// <param name="pqueue">要出队的队列，Queue类型的结构体指针</param>
void QueuePop(Queue* pqueue)
{
	assert(pqueue);
	assert(pqueue->phead);//队列里面必须要有数据才可以弹出

	//头删
	if (pqueue->phead->next == NULL)//一个节点
	{
		free(pqueue->phead);
		pqueue->phead = pqueue->ptail = NULL;
	}
	else//多个节点
	{
		QNode* tmpQNode = pqueue->phead;
		pqueue->phead = pqueue->phead->next;
		//释放节点
		free(tmpQNode);
	}
	pqueue->size--;
}

/// <summary>
/// 链表实现队列，队列销毁函数。
/// </summary>
/// <param name="pqueue">要销毁的队列，Queue类型的结构体指针</param>
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
/// 链表实现队列，队列是否为空函数。
/// </summary>
/// <param name="pqueue">要查看的队列，Queue类型的结构体指针</param>
/// <returns>为空返回 true  不为空返回false</returns>
bool QueueEmpty(Queue* pqueue)
{
	assert(pqueue);

	return !(pqueue->phead);
}

/// <summary>
/// 链表实现队列，查看队列有效元素个数函数。
/// </summary>
/// <param name="pqueue">要查看那个队列，Queue类型的结构体指针</param>
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
/// 链表实现队列，查看队列头部元素函数。
/// </summary>
/// <param name="pqueue">要查看那个队列，Queue类型的结构体指针</param>
/// <returns>返回队列头部元素的值</returns>
QDataType QueueFront(Queue* pqueue)
{
	assert(pqueue);
	assert(pqueue->phead);//队列中不可以没有元素

	return pqueue->phead->val;
}

/// <summary>
/// 链表实现队列，查看队列尾部元素函数。
/// </summary>
/// <param name="pqueue">要查看那个队列，Queue类型的结构体指针</param>
/// <returns>返回队列尾部元素的值</returns>
QDataType QueueBack(Queue* pqueue)
{
	assert(pqueue);
	assert(pqueue->phead);//队列中不可以没有元素

	return pqueue->ptail->val;
}
