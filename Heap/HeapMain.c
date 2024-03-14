#include "Heap.h"

int main()
{
	HP hp;
	HP_Init(&hp);
	//int a[] = { 50,100,70,65,60,32 };
	int a[] = { 3,2,5,4,1,6 };

	HeapSort(a, 6);

	return 0;
}