#include "BidirectionalLinkedList.h"

int main()
{
	BLL_Node* phead = BLL_Init();

	//尾插
	BLL_PushBack(phead, 1);
	BLL_PushBack(phead, 2);
	BLL_PushBack(phead, 5);

	//头插
	BLL_PushFront(phead, 3);
	BLL_PushFront(phead, 4);

	//尾删
	BLL_PopBack(phead);
	BLL_PopBack(phead);

	//头删
	BLL_PopFront(phead);
	BLL_PopFront(phead);

	//查找节点
	if (BLL_Find(phead, 5))
	{
		printf("找到了！\n");
	}
	else
	{
		printf("未找到！\n");
	}

	//指定位置之后插入数据
	BLL_Insert(BLL_Find(phead, 1), 8);

	//指定位置删除数据
	BLL_Erase(BLL_Find(phead, 8));

	//打印链表
	BLL_Print(phead);

	//销毁链表
	//BLL_DesTroy(&phead);
	BLL_DesTroy(phead);
	phead = NULL;

	if (phead == NULL)
	{
		printf("哨兵节点已销毁！\n");
	}
	else
	{
		printf("哨兵节点销毁出错！\n");
	}

	return 0;
}