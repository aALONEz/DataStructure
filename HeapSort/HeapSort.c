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
	int tmp = i * 2 + 1;//���ӽڵ�����
	while (tmp < size)//tmp�����Գ��������С
	{
		if (tmp + 1 < size && arr[tmp + 1] < arr[tmp])//С��
		//if (tmp + 1 < size && arr[tmp + 1] > arr[tmp])//���//tmp + 1���ӽڵ�,���ӽڵ��±겻���Գ�������Ĵ�С
		{
			tmp++;
		}
		if (arr[tmp] < arr[i])//С��
		//if (arr[tmp] > arr[i])//���
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
	//������Ļ�����ֱ�ӽ���
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//(n - 1 - 1) / 2�ӵ�һ����Ҷ�ӽڵ㿪ʼ���ѣ���Ϊ���µ���ʱҶ�ӽڵ㲻��Ҫ������Ϊֻ�����Լ���n - 1�����һ����Ч���ݵ��±꣬����n - 1��- 1��/ 2�Ǽ������һ����Ч���ݵĸ��ڵ��±�
	{
		//ʹ�����µ����㷨
		AdjustDown(a, n, i);
	}
	//��ɶ�֮���Ҫ���������ˣ������ǰ�������������������������Ҫ�Ǵ�ѣ�Ȼ��Ѷ�������������ֵ��Ȼ���������ֵ�����������һ�������е�����Ȼ���ٽ������µ����㷨����ʱ���е����µ����㷨Ҫ������ֵ�ų����⡣
	int newsize = n;//�����С
	while (newsize > 1)//�����鵱ǰ�Ĵ�СΪ0��ʱ����Ѿ�����Ҫ�����ˣ���Ϊ���������ʣ��һ��������
	{
		//��β���ݽ���
		Swap(&(a[0]), &(a[newsize - 1]));//newsize - 1 ���һ����Ч���ݵ��±�
		newsize -= 1;//����λ�ú��С����Ĵ�С
		AdjustDown(a, newsize, 0);//����ڶ����������ݵ�������Ĵ�С
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

	//ʹ��ǰ10�����ݼ�С��
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
	//��С��
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, k, i);
	}
	//�öѶ������ݺ�ʣ�����ݶԱ�
	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])//���ھ��滻
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}

	////��ǰk��������ٴν�������
	//int newsize = k;
	//while (newsize > 1)
	//{
	//	//��β����
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
