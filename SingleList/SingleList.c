#include "SingleList.h"

/*
* 函数名：SLPrintInt
* 用途：单链表的打印整数函数。
* 参数：data 要打印的值的地址
* 返回值：无
* 备注：无
*/
void SLPrintInt(void *data)
{
	printf("%d->", *((int *)data));
}

/*
* 函数名：NewNode
* 用途：单链表的申请新节点函数。
* 参数：x 新节点的数据，也就是data成员的值
* 返回值：新节点的地址
* 备注：无
*/
static SingleListNode *NewNode(ListDataType x)
{
	SingleListNode *newSL_Node = (SingleListNode *)malloc(sizeof(SingleListNode));
	newSL_Node->data = x;
	newSL_Node->next = NULL;
	return newSL_Node;
}

/*
* 函数名：SingleList_Print
* 用途：单链表的打印函数。
* 参数：pSL_Node 要操作的单链表的头节点指针
*		SLPrint 打印函数的指针，函数头为void SLPrint(void *data)
* 返回值：无
* 备注：无
*/
void SingleList_Print(SingleListNode *pSL_Node, void SLPrint(void *data))
{
	SingleListNode *tmpSL_Node = pSL_Node;
	while (tmpSL_Node)
	{
		//打印函数
		SLPrint(&(tmpSL_Node->data));
		tmpSL_Node = tmpSL_Node->next;
	}
	printf("NULL\n");
}

/*
* 函数名：SingleList_PushBack
* 用途：单链表的尾部插入函数。
* 参数：ppSL_Node 要操作的单链表的头节点的二级指针
*		x 要插入的节点数据
* 返回值：无
* 备注：无
*/
void SingleList_PushBack(SingleListNode **ppSL_Node, ListDataType x)//这里要接收二级指针否则就是传值，只有传地址才可以改变它指向的内容
{
	assert(ppSL_Node);
	//创建新的节点并赋值
	SingleListNode *newSL_Node = NewNode(x);//经常申请新节点直接将申请新节点封装为一个函数
	//没有有效节点
	if (*ppSL_Node == NULL)
	{
		*ppSL_Node = newSL_Node;
		return;
	}
	//具有有效节点
	SingleListNode *tmpSL_Node = *ppSL_Node;
	while (tmpSL_Node->next)
	{
		tmpSL_Node = tmpSL_Node->next;
	}
	//链接
	tmpSL_Node->next = newSL_Node;
}

/*
* 函数名：SingleList_PushBack
* 用途：单链表的头部插入函数。
* 参数：ppSL_Node 要操作的单链表的头节点的二级指针
*		x 要插入的节点数据
* 返回值：无
* 备注：无
*/
void SingleList_PushFront(SingleListNode **ppSL_Node, ListDataType x)
{
	assert(ppSL_Node);
	//创建新的节点并赋值
	SingleListNode *newSL_Node = NewNode(x);//经常申请新节点直接将申请新节点封装为一个函数
	newSL_Node->next = *ppSL_Node;	//将新节点的next成员的值赋值为当前头节点
	*ppSL_Node = newSL_Node;		//再将头节点赋值为newSL_Node节点
}

/*
* 函数名：SingleList_PopBack
* 用途：单链表的尾部删除函数。
* 参数：ppSL_Node 要操作的单链表的头节点的二级指针
* 返回值：无
* 备注：无
*/
void SingleList_PopBack(SingleListNode **ppSL_Node)
{
	//链表不能为空
	assert(ppSL_Node && *ppSL_Node);
	//判断链表是不是只有一个节点
	if ((*ppSL_Node)->next == NULL)
	{
		free(*ppSL_Node);
		*ppSL_Node = NULL;
		return;
	}
	//多个节点
	SingleListNode *ptailSL_Node = *ppSL_Node;
	SingleListNode *prevSL_Node = NULL;
	while (ptailSL_Node->next)
	{
		prevSL_Node = ptailSL_Node;
		ptailSL_Node = ptailSL_Node->next;
	}
	//销毁尾节点
	free(ptailSL_Node);
	ptailSL_Node = NULL;
	//将新的尾节点的next成员设置为NULL
	prevSL_Node->next = NULL;
}

/*
* 函数名：SingleList_PopFront
* 用途：单链表的头部删除函数。
* 参数：ppSL_Node 要操作的单链表的头节点的二级指针
* 返回值：无
* 备注：无
*/
void SingleList_PopFront(SingleListNode **ppSL_Node)
{
	//链表不能为空
	assert(ppSL_Node && *ppSL_Node);
	//创建临时节点，保存下个节点的地址
	SingleListNode *tmpSL_Node = (*ppSL_Node)->next;
	//释放头部节点
	free(*ppSL_Node);
	//重新指定头部节点地址
	*ppSL_Node = tmpSL_Node;
}