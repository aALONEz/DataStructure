#include "SeqList.h"
#include "stdio.h"

int main()
{
	DynamicSeqList DSL;
	DSL_Init(&DSL);
	DSL_PopBack(&DSL);
	DSL_PushBack(&DSL, 1);
	DSL_PushBack(&DSL, 2);
	DSL_PushBack(&DSL, 3);
	DSL_PushBack(&DSL, 4);
	DSL_Insert(&DSL, 0, 8);
	DSL_PushBack(&DSL, 5);
	DSL_PushBack(&DSL, 6);
	DSL_PushFront(&DSL, 0);
	DSL_PopBack(&DSL);
	DSL_PopFront(&DSL);
	DSL_Insert(&DSL, 3, 7);
	DSL_Erase(&DSL, 5);
	printf("%d\n", DSL_Find(&DSL, 9));
	DSL_Modify(&DSL, DSL_Find(&DSL, 8), 7);

	for (int i = 0; i < DSL.length; i++)
	{
		printf("%d\n", DSL.a[i]);
	}
}