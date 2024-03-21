#include "Sort.h"

static void Swap(int* val1, int* val2)
{
	int tmpnum = *val1;
	*val1 = *val2;
	*val2 = tmpnum;
}

void PrintArr(SortType* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/// <summary>
/// ��������
/// </summary>
/// <param name="arr">����������</param>
/// <param name="size">�������Ԫ�ظ���</param>
void InsertSort(SortType* arr, int size)
{
	for (int j = 0; j < size - 1; j++)//j��ʾ���һ������Ԫ�ص��±�
	{
		//�������򣬽�end��j�� + 1���뵽0-end��j������
		SortType tmp = arr[j + 1];//tmp����������ֵ����������jҪС��size-1�����j���������һ��Ԫ�ص��±�ʱ����ô�������Ԫ�ؾͳ���������
		int i = j;
		for (; i >= 0; i--)
		{
			//����
			if (tmp < arr[i])
			{
				arr[i + 1] = arr[i];//����tmpС�ڵ�ǰλ�õ�ֵ�ͽ���ǰλ�õ�ֵ���Ų��һλ
			}
			else//����tmp��ȥ����λ��
			{
				break;
			}
		}
		arr[i + 1] = tmp;//��tmp��ֵ��ֵ����λ��
	}
}

/// <summary>
/// ð������
/// </summary>
/// <param name="arr">�����������</param>
/// <param name="size">�������Ԫ�ظ���</param>
void BubbleSort(SortType* arr, int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		int flag = 0;//��־λ��������浥����û�з������ݵĽ�����˵���Ѿ���������ˣ���ô������ѭ����
		for (int i = 0; i < size - j - 1; i++)
		{
			//����
			if (arr[i + 1] < arr[i])//���i+1�±��Ԫ��С��i�±��Ԫ�ؾͽ���
			{
				flag = 1;
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

/// <summary>
/// ϣ������
/// </summary>
/// <param name="arr">�����������</param>
/// <param name="size">�������Ԫ�ظ���</param>
void ShellSort(SortType* arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//gap�齻����в�������
		for (int i = 0; i < size - gap; i++)
		{
			//��������
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				//����
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

/// <summary>
/// ������ʹ�õ����µ����㷨
/// </summary>
/// <param name="val">�����µ���������</param>
/// <param name="size">����Ĵ�С</param>
/// <param name="i">��i�±꿪ʼ���µ���</param>
static void AdjustDown(SortType* val, int size, int i)
{
	int tmp = i * 2 + 1;
	while (tmp < size)//��һ���ڵ�������±곬�������С����ôҲ����˵������ڵ�û�������ӣ�����ڵ���һ��Ҷ�ӽڵ㡣
	{
		//����������������������С��
		//if (tmp + 1 < size && val[tmp + 1] < val[tmp])//��С��
		if (tmp + 1 < size && val[tmp + 1] > val[tmp])//����,tmp + 1 < size��Ϊ�˱�֤�����Һ��ӣ�����������Һ��ӾͿ϶�ֻ��������С����ֹ����Խ��
		{
			tmp += 1;
		}
		//if (val[tmp] < val[i])//��С��
		if (val[tmp] > val[i])//����
		{
			Swap(&(val[i]), &(val[tmp]));//���½���
			i = tmp;
			tmp = i * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

/// <summary>
/// ������
/// </summary>
/// <param name="arr">�����������</param>
/// <param name="size">�������Ԫ�ظ���</param>
void HeapSort(SortType* arr, int size)
{
	//����
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, size, i);
	}

	while (size > 1)
	{
		//����
		Swap(&arr[0], &arr[size - 1]);//��β���ݽ���
		size--;
		AdjustDown(arr, size, 0);//�������µ�������
	}
}

//void SelectSort(SortType* arr, int size)
//{
//	int end = -1;//�����������ĩβ�±�
//	int min = 0;//δ����������Сֵ���±�
//
//	while (end < size - 1)//С��size-1�����������������һ��Ԫ�ص��±굽�����ڶ���Ԫ�ص��±�ֵ
//	{
//		//�ҳ�δ�����������Сֵ
//		for (int i = end + 1 + 1; i < size; i++)//iֱ�Ӵ�δ��������ĵڶ���Ԫ�ؿ�ʼ����Ϊ��һ��Ԫ���Ѿ��ٶ�Ϊ��Сֵ
//		{
//			if (arr[i] < arr[min])
//			{
//				min = i;
//			}
//		}
//		end++;//������ռ��1
//		//��������
//		int tmp = arr[end];
//		arr[end] = arr[min];
//		arr[min] = tmp;
//		//���¼ٶ�����Сֵ�±�
//		min = end + 1;
//	}
//}

/// <summary>
/// ѡ������
/// </summary>
/// <param name="arr">�����������</param>
/// <param name="size">�������Ԫ�ظ���</param>
void SelectSort(SortType* arr, int size)
{
	int min = 0;//��СԪ�ص��±�
	int max = 0;//���Ԫ�ص��±�
	int left = 0;//���ָ��
	int right = size - 1;//�Ҳ�ָ��

	while (left < right)
	{
		for (int i = left + 1; i <= right; i++)//i�����ָ����Ҳ�ָ����
		{
			if (arr[i] < arr[min])//��Сֵ
			{
				min = i;
				continue;
			}
			if (arr[i] > arr[max])//���ֵ
			{
				max = i;
				continue;
			}
		}

		//��Сֵ��������
		int tmp = arr[left];
		arr[left] = arr[min];
		arr[min] = tmp;

		if (max == left)//�ж����ֵ�±��Ƿ��غ�
		{
			max = min;
		}
		tmp = arr[right];
		arr[right] = arr[max];
		arr[max] = tmp;

		left++;
		right--;
		max = left;
		min = left;
	}
}

void QuickSort(SortType* arr, int left, int right)
{
	if (left >= right)//������ֻ��һ��ֵ����������û��ֵ���ͷ��ء�һ��ֵ�ǵ��ڣ�û��ֵ�Ǵ���
	{
		return;
	}
	int start = left;
	int end = right;
	int pivot = left;//ѡ���һ��Ԫ����Ϊ��׼

	while (left < right)
	{
		while (arr[right] >= arr[pivot] && left < right)//�ұ��ұȻ�׼С�ģ�����һ��Ҫ�������ڣ�Ҫ��Ȼ�������׼ֵ��ȵ�ʱ�������ѭ��
		{
			right--;
		}
		while (arr[left] <= arr[pivot] && left < right)//����ұȻ�׼ֵ��ģ����ﲻ�������ж�����ֱ��++����--��Ϊ�жϵ�ʱ��Ҳ��ִ�����μӼӼ���
		{
			left++;
		}
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
	}
	int tmp = arr[left];
	arr[left] = arr[pivot];
	arr[pivot] = tmp;

	pivot = left;

	// ��start ~ pivot - 1��pivot��pivot + 1 ~ end��
	QuickSort(arr, start, pivot - 1);//������ݹ�
	QuickSort(arr, pivot + 1, end);//������ݹ�
}

