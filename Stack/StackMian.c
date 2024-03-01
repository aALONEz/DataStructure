#include "Stack.h"

int main()
{
	ST tmp;
	ST_Init(&tmp);
	ST_Push(&tmp, 1);
	ST_Push(&tmp, 2);
	ST_Push(&tmp, 3);
	ST_Push(&tmp, 4);
	ST_Push(&tmp, 5);
	ST_Pop(&tmp);
	printf("%d\n", ST_Top(&tmp));//4
	printf("%d\n", ST_Top(&tmp));//4
	ST_Pop(&tmp);
	printf("%d\n", ST_Top(&tmp));//3
	printf("%d\n", ST_Size(&tmp));//3
	printf("%d\n", ST_Empty(&tmp));//0
	ST_Destroy(&tmp);
	printf("%d\n", ST_Empty(&tmp));//1
	return;
}
