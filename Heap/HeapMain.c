#include "Heap.h"

int main()
{
	HP hp;
	HP_Init(&hp);
	//int a[] = { 50,100,70,65,60,32 };
	int a[] = { 3,2,5,4,1,6 };

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		HP_Push(&hp, a[i]);
	}

	for (int i = 0; i < hp.size; i++)
	{
		printf("%d ", hp.val[i]);
	}
	printf("\n");

	while (!HP_Empty(&hp))
	{
		printf("%d ", HP_Top(&hp));
		HP_Pop(&hp);
	}
	HP_Destroy(&hp);

	return 0;
}