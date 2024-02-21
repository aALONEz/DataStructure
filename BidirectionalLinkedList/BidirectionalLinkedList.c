#include "BidirectionalLinkedList.h"

/*
* 函数名：NewNode
* 用途：双向链表申请新节点函数。
* 参数：data 新节点的数据位的值。
* 返回值：新节点的指针
* 备注：次函数只可本文件调用。
*/
static BLL_Node* NewNode(BLL_DataType data)
{
	BLL_Node* tmpNode = (BLL_Node*)malloc(sizeof(BLL_Node));
	if (tmpNode == NULL)
	{
		perror("malloc出错！\n");
		exit(1);
	}
	tmpNode->data = data;
	(tmpNode)->next = (tmpNode);
	(tmpNode)->prev = (tmpNode);
	return tmpNode;
}

/*
* 函数名：BLL_Init
* 用途：双向链表初始化。
* 参数：无
* 返回值：头节点的指针
* 备注：无
*/
BLL_Node* BLL_Init(void)
{
	return NewNode(0);
}

/*
* 函数名：BLL_PushBack
* 用途：双向链表的尾插函数。
* 参数：phead 要操作的链表的哨兵节点的地址
*		data 要插入的数据
* 返回值：无
* 备注：无
*/
void BLL_PushBack(BLL_Node* phead, BLL_DataType data)
{
	//判断哨兵节点不可以为空
	assert(phead);
	//申请新的节点
	BLL_Node* newNode = NewNode(data);
	//链接尾节点
	newNode->next = phead;
	newNode->prev = (phead->prev);
	(phead->prev)->next = newNode;
	phead->prev = newNode;
	
}

/*
* 函数名：BLL_PushFront
* 用途：双向链表的头插函数。
* 参数：phead 要操作的链表的哨兵节点的地址
*		data 要插入的数据
* 返回值：无
* 备注：无
*/
void BLL_PushFront(BLL_Node* phead, BLL_DataType data)
{
	//判断哨兵节点不为NULL
	assert(phead);
	//申请新节点
	BLL_Node* newNode = NewNode(data);
	//头插新节点
	newNode->prev = phead;
	newNode->next = phead->next;
	(phead->next)->prev = newNode;
	phead->next = newNode;
}

/*
* 函数名：BLL_Print
* 用途：双向链表的打印函数。
* 参数：phead 要操作的链表的哨兵节点的地址
* 返回值：无
* 备注：无
*/
void BLL_Print(BLL_Node* phead)
{
	//判断哨兵节点不为NULL
	assert(phead);
	//拷贝一份哨兵节点
	BLL_Node* tmpNode = phead;
	while (tmpNode->next != phead)
	{
		tmpNode = tmpNode->next;//先让当前节点移动到下一个节点，因为头节点是没有数据的
		printf("%d->", tmpNode->data);
	}
	printf("头节点\n");
}

/*
* 函数名：BLL_PopBack
* 用途：双向链表的尾删函数。
* 参数：phead 要操作的链表的哨兵节点的地址
* 返回值：无
* 备注：无
*/
void BLL_PopBack(BLL_Node* phead)
{
	//判断哨兵节点不为NULL
	assert(phead);
	//判断链表内有无有效节点
	if (phead->next == phead)
	{
		perror("尾删错误，无有效节点\n");
		exit(1);
	}
	//创建临时节点，保存当前尾节点
	BLL_Node* tmpNode = phead->prev;
	//哨兵节点重新链接新的尾节点
	phead->prev = tmpNode->prev;
	(tmpNode->prev)->next = phead;

	free(tmpNode);
	tmpNode = NULL;
}

/*
* 函数名：BLL_PopFront
* 用途：双向链表的头删函数。
* 参数：phead 要操作的链表的哨兵节点的地址
* 返回值：无
* 备注：无
*/
void BLL_PopFront(BLL_Node* phead)
{
	//判断哨兵节点不为NULL
	assert(phead);
	//判断链表内有无有效节点
	if (phead->next == phead)
	{
		perror("头删错误，无有效节点\n");
		exit(1);
	}
	//创建临时节点，保存当前第一个有效节点
	BLL_Node* tmpNode = phead->next;
	//重新链接节点
	phead->next = tmpNode->next;
	(tmpNode->next)->prev = phead;

	free(tmpNode);
	tmpNode = NULL;
}

/*
* 函数名：BLL_Find
* 用途：双向链表的查找函数。
* 参数：phead 要操作的链表的哨兵节点的地址
*		data 要查找的值
* 返回值：存在这个值的节点
* 备注：无
*/
BLL_Node* BLL_Find(BLL_Node* phead, BLL_DataType data)
{
	assert(phead);
	BLL_Node* tmpNode = phead->next;
	while (tmpNode != phead)
	{
		if (data == tmpNode->data)
		{
			return tmpNode;
		}
		tmpNode = tmpNode->next;
	}
	return NULL;
}

/*
* 函数名：BLL_Insert
* 用途：双向链表的指定位置之后插入数据的函数。
* 参数：posNode 指定的节点指针
*		data 要插入的数据
* 返回值：无
* 备注：无
*/
void BLL_Insert(BLL_Node* posNode, BLL_DataType data)
{
	assert(posNode);

	BLL_Node* newNode = NewNode(data);

	newNode->next = posNode->next;
	newNode->prev = posNode;
	(posNode->next)->prev = newNode;
	posNode->next = newNode;
}

/*
* 函数名：BLL_Erase
* 用途：双向链表的指定位置删除数据的函数。
* 参数：posNode 指定的节点指针
* 返回值：无
* 备注：无
*/
void BLL_Erase(BLL_Node* posNode)
{
	assert(posNode);

	BLL_Node* tmpNode = posNode;
	(tmpNode->next)->prev = tmpNode->prev;
	(tmpNode->prev)->next = tmpNode->next;

	free(tmpNode);
	tmpNode = NULL;
}

///*
//* 函数名：BLL_DesTroy
//* 用途：双向链表的销毁函数。
//* 参数：pphead 要销毁的链表的二级指针
//* 返回值：无
//* 备注：无
//*/
//void BLL_DesTroy(BLL_Node** pphead)
//{
//	assert(pphead);
//	assert(*pphead);
//
//	BLL_Node* tmpNode = (*pphead)->next;
//	
//	while (tmpNode != (*pphead))
//	{
//		BLL_Node* nextNode = tmpNode->next;
//		free(tmpNode);
//		tmpNode = nextNode;
//	}
//	free(*pphead);
//	*pphead = NULL;//将哨兵节点置为NULL
//}

/*
* 函数名：BLL_DesTroy
* 用途：双向链表的销毁函数。
* 参数：phead 要销毁的链表的指针
* 返回值：无
* 备注：无
*/
void BLL_DesTroy(BLL_Node* phead)
{
	assert(phead);

	BLL_Node* tmpNode = phead->next;

	while (tmpNode != phead)
	{
		BLL_Node* nextNode = tmpNode->next;
		free(tmpNode);
		tmpNode = nextNode;
	}
	free(phead);
}