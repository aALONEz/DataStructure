#include "SingleList.h"

int main()
{
	SingleListNode *SL_Node = NULL;

	SingleList_PushBack(&SL_Node, 25);//这里要传递节点地址的地址，因为如果传递的是节点的地址，只是把这个指针变量传递过去了实际上是传值调用，是向这个函数传递这个节点地址的拷贝，而我们函数里面要修改这个地址的值，所以要传递这个节点地址指针的地址才可以修改这个节点指针变量的值。
	SingleList_PushBack(&SL_Node, 26);
	SingleList_PushBack(&SL_Node, 27);
	SingleList_PushBack(&SL_Node, 28);
	SingleList_PushFront(&SL_Node, 24);

	SingleList_PopBack(&SL_Node);
	SingleList_PopFront(&SL_Node);
	SingleList_Print(&SL_Node, SLPrintInt);//注意这里节点名已经是指针了不需要再次取地址了。
	SingleList_Insert(&SL_Node, SingleList_Find(&SL_Node, 25), 24);
	SingleList_InsertAfter(SL_Node, 23);
	SingleList_InsertAfter(SingleList_Find(&SL_Node, 27), 28);
	SingleList_Erase(&SL_Node, SingleList_Find(&SL_Node, 28));
	SingleList_EraseAfter(SingleList_Find(&SL_Node, 26));
	SingleList_Print(&SL_Node, SLPrintInt);//注意这里节点名已经是指针了不需要再次取地址了。
	SingleList_DesTroy(&SL_Node);
	return 0;
}