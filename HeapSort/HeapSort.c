#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Swap(int* val1, int* val2)
{
	int tmpnum = *val1;
	*val1 = *val2;
	*val2 = tmpnum;
}

void AdjustDown(int* arr, int size, int i)
{
	int tmp = i * 2 + 1;//左子节点索引
	while (tmp < size)//tmp不可以超过数组大小
	{
		if (tmp + 1 < size && arr[tmp + 1] < arr[tmp])//小堆
		//if (tmp + 1 < size && arr[tmp + 1] > arr[tmp])//大堆//tmp + 1右子节点,右子节点下标不可以超过数组的大小
		{
			tmp++;
		}
		if (arr[tmp] < arr[i])//小堆
		//if (arr[tmp] > arr[i])//大堆
		{
			Swap(&(arr[tmp]), &(arr[i]));
			i = tmp;
			tmp = i * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//在数组的基础上直接建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//(n - 1 - 1) / 2从第一个非叶子节点开始建堆，因为向下调整时叶子节点不需要调整因为只有她自己，n - 1是最后一个有效数据的下标，（（n - 1）- 1）/ 2是计算最后一个有效数据的父节点下标
	{
		//使用向下调整算法
		AdjustDown(a, n, i);
	}
	//组成堆之后就要进行排序了，现在是按照升序排序，如果是升序排序就要是大堆，然后堆顶的数据是最大的值，然后将这个最大的值和数组中最后一个数进行调换，然后再进行向下调整算法，此时进行的向下调整算法要将最大的值排除在外。
	int newsize = n;//数组大小
	while (newsize > 1)//当数组当前的大小为0的时候就已经不需要交换了，因为数组里面就剩下一个数据了
	{
		//首尾数据交换
		Swap(&(a[0]), &(a[newsize - 1]));//newsize - 1 最后一个有效数据的下标
		newsize -= 1;//交换位置后减小数组的大小
		AdjustDown(a, newsize, 0);//这里第二个参数传递的是数组的大小
	}
}

void CreateNData(int n)
{
	srand(time(NULL));

	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("CreateNData:fin");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 10000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void Topk(int k)
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("main:fout");
		return;
	}

	//使用前10个数据减小堆
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("main:malloc");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}
	//建小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, k, i);
	}
	//让堆顶的数据和剩下数据对比
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])//大于就替换
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}

	////将前k大的数据再次进行排序
	//int newsize = k;
	//while (newsize > 1)
	//{
	//	//首尾交换
	//	Swap(&minHeap[0], &minHeap[newsize - 1]);
	//	newsize--;
	//	AdjustDown(minHeap, newsize, 0);
	//}

	for (int i = 0; i < k; i++)
	{
		printf("%d\n", minHeap[i]);
	}


	free(minHeap);
	fclose(fout);
}

int main()
{
	//CreateNData(100000000);

	Topk(10);

	return 0;
}
