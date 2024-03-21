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
/// 插入排序
/// </summary>
/// <param name="arr">待排序数组</param>
/// <param name="size">待排序的元素个数</param>
void InsertSort(SortType* arr, int size)
{
	for (int j = 0; j < size - 1; j++)//j表示最后一个有序元素的下标
	{
		//单趟排序，将end（j） + 1插入到0-end（j）里面
		SortType tmp = arr[j + 1];//tmp保存待排序的值，所以上面j要小于size-1，如果j是数组最后一个元素的下标时，那么待排序的元素就超出了数组
		int i = j;
		for (; i >= 0; i--)
		{
			//升序
			if (tmp < arr[i])
			{
				arr[i + 1] = arr[i];//升序当tmp小于当前位置的值就将当前位置的值向后挪动一位
			}
			else//到达tmp该去到的位置
			{
				break;
			}
		}
		arr[i + 1] = tmp;//将tmp的值赋值到该位置
	}
}

/// <summary>
/// 冒泡排序
/// </summary>
/// <param name="arr">待排序的数组</param>
/// <param name="size">待排序的元素个数</param>
void BubbleSort(SortType* arr, int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		int flag = 0;//标志位，如果下面单趟中没有发生数据的交换就说明已经是有序的了，那么就跳出循环。
		for (int i = 0; i < size - j - 1; i++)
		{
			//升序
			if (arr[i + 1] < arr[i])//如果i+1下标的元素小于i下标的元素就交换
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
/// 希尔排序
/// </summary>
/// <param name="arr">待排序的数组</param>
/// <param name="size">待排序的元素个数</param>
void ShellSort(SortType* arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//gap组交替进行插入排序
		for (int i = 0; i < size - gap; i++)
		{
			//单租排序
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				//升序
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
/// 堆排序使用的向下调整算法
/// </summary>
/// <param name="val">待向下调整的数组</param>
/// <param name="size">数组的大小</param>
/// <param name="i">从i下标开始向下调整</param>
static void AdjustDown(SortType* val, int size, int i)
{
	int tmp = i * 2 + 1;
	while (tmp < size)//当一个节点的左孩子下标超出数组大小，那么也就是说明这个节点没有做孩子，这个节点是一个叶子节点。
	{
		//假设左孩子是两个孩子中最小的
		//if (tmp + 1 < size && val[tmp + 1] < val[tmp])//最小堆
		if (tmp + 1 < size && val[tmp + 1] > val[tmp])//最大堆,tmp + 1 < size是为了保证具有右孩子，如果不具有右孩子就肯定只有左孩子最小，防止数组越界
		{
			tmp += 1;
		}
		//if (val[tmp] < val[i])//最小堆
		if (val[tmp] > val[i])//最大堆
		{
			Swap(&(val[i]), &(val[tmp]));//向下交换
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
/// 堆排序
/// </summary>
/// <param name="arr">待排序的数组</param>
/// <param name="size">待排序的元素个数</param>
void HeapSort(SortType* arr, int size)
{
	//建堆
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, size, i);
	}

	while (size > 1)
	{
		//排序
		Swap(&arr[0], &arr[size - 1]);//首尾数据交换
		size--;
		AdjustDown(arr, size, 0);//重新向下调整建堆
	}
}

//void SelectSort(SortType* arr, int size)
//{
//	int end = -1;//已排序区间的末尾下标
//	int min = 0;//未排序区间最小值的下标
//
//	while (end < size - 1)//小于size-1就是让有序序列最后一个元素的下标到倒数第二个元素的下标值
//	{
//		//找出未排序区间的最小值
//		for (int i = end + 1 + 1; i < size; i++)//i直接从未排序区间的第二个元素开始，因为第一个元素已经假定为最小值
//		{
//			if (arr[i] < arr[min])
//			{
//				min = i;
//			}
//		}
//		end++;//已排序空间加1
//		//交换数据
//		int tmp = arr[end];
//		arr[end] = arr[min];
//		arr[min] = tmp;
//		//重新假定定最小值下标
//		min = end + 1;
//	}
//}

/// <summary>
/// 选择排序
/// </summary>
/// <param name="arr">待排序的数组</param>
/// <param name="size">待排序的元素个数</param>
void SelectSort(SortType* arr, int size)
{
	int min = 0;//最小元素的下标
	int max = 0;//最大元素的下标
	int left = 0;//左侧指针
	int right = size - 1;//右侧指针

	while (left < right)
	{
		for (int i = left + 1; i <= right; i++)//i在左侧指针和右侧指针内
		{
			if (arr[i] < arr[min])//最小值
			{
				min = i;
				continue;
			}
			if (arr[i] > arr[max])//最大值
			{
				max = i;
				continue;
			}
		}

		//最小值交换数据
		int tmp = arr[left];
		arr[left] = arr[min];
		arr[min] = tmp;

		if (max == left)//判断最大值下标是否重合
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
	if (left >= right)//区间内只有一个值或者区间内没有值，就返回。一个值是等于，没有值是大于
	{
		return;
	}
	int start = left;
	int end = right;
	int pivot = left;//选择第一个元素作为基准

	while (left < right)
	{
		while (arr[right] >= arr[pivot] && left < right)//右边找比基准小的，这里一定要带个等于，要不然会让与基准值相等的时候进入死循环
		{
			right--;
		}
		while (arr[left] <= arr[pivot] && left < right)//左边找比基准值大的，这里不可以在判断里面直接++或者--因为判断的时候也会执行依次加加减减
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

	// 【start ~ pivot - 1】pivot【pivot + 1 ~ end】
	QuickSort(arr, start, pivot - 1);//左区间递归
	QuickSort(arr, pivot + 1, end);//右区间递归
}

