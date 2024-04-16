#include "Sort.h"
#include <time.h>
#include <stdlib.h>

void TestOP(void)
{
	srand(time(NULL));
	const int n = 100000;
	SortType* arr1 = (SortType*)malloc(sizeof(SortType) * n);
	SortType* arr2 = (SortType*)malloc(sizeof(SortType) * n);
	SortType* arr3 = (SortType*)malloc(sizeof(SortType) * n);
	SortType* arr4 = (SortType*)malloc(sizeof(SortType) * n);
	SortType* arr5 = (SortType*)malloc(sizeof(SortType) * n);
	SortType* arr6 = (SortType*)malloc(sizeof(SortType) * n);

	for (int i = 0; i < n; i++)
	{
		arr1[i] = rand();
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
		arr4[i] = arr1[i];
		arr5[i] = arr1[i];
		arr6[i] = arr1[i];
	}
	int begin = 0;
	int end = 0;

	//clock()��ȡ��ǰϵͳ�ĺ���ʱ���
	printf("��������\n");
	begin = clock();
	InsertSort(arr1, n);
	end = clock();
	printf("����ʱ��%d\n", end - begin);
	printf("\n\n");

	printf("ð������\n");
	begin = clock();
	BubbleSort(arr2, n);
	end = clock();
	printf("����ʱ��%d\n", end - begin);
	printf("\n\n");

	printf("ϣ������\n");
	begin = clock();
	ShellSort(arr2, n);
	end = clock();
	printf("����ʱ��%d\n", end - begin);
	printf("\n\n");

	printf("������\n");
	begin = clock();
	HeapSort(arr2, n);
	end = clock();
	printf("����ʱ��%d\n", end - begin);
	printf("\n\n");

	printf("ѡ������\n");
	begin = clock();
	SelectSort(arr2, n);
	end = clock();
	printf("����ʱ��%d\n", end - begin);
	printf("\n\n");
}

int main()
{
	int arr[] = { 10,5,6,7,8,1,2,3,4,9 };
	//TestOP();
	MergeSort(arr, 10);
	PrintArr(arr, 10);

	return 0;
}
