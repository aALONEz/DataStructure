#include "Heap.h"

/// <summary>
/// 堆的初始化函数
/// </summary>
/// <param name="php">堆结构体变量的指针</param>
void HP_Init(HP* php)
{
	assert(php);
	php->val = NULL;
	php->size = 0;
	php->capacity = 0;
}

/// <summary>
/// 堆的销毁函数
/// </summary>
/// <param name="php">堆结构体变量的指针</param>
void HP_Destroy(HP* php)
{
	assert(php);
	assert(php->val);

	free(php->val);
	php->val = NULL;
	php->size = 0;
	php->capacity = 0;
}

/// <summary>
/// 内部调用的交换函数
/// </summary>
/// <param name="val1">要交换的数据1</param>
/// <param name="val2">要交换的数据2</param>
static void Swap(HPDataType* val1, HPDataType* val2)
{
	HPDataType tmpval = *val1;
	*val1 = *val2;
	*val2 = tmpval;
}

/// <summary>
/// 插入数据之后让数据保持堆的特性的向上调整算法
/// </summary>
/// <param name="val">存储堆数据的数组指针</param>
/// <param name="i">最后一个有效数据的下标</param>
static void AdjustUp(HPDataType* val, int i)
{
	while (i > 0)//这里只需要大于，不需要大于等于
	{
		//if (val[i] < val[(i - 1) / 2])//最小堆
		if (val[i] > val[(i - 1) / 2])//最大堆,这里的逻辑比较不可以大于等于只可以大于，要不然会出现死循环，假如当这个新插入的数据是整个堆最大的值，如果是大于等于就会死循环
		{
			
			Swap(&(val[i]), &(val[(i - 1) / 2]));
			i = (i - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

/// <summary>
/// 删除数据后让数据保持堆特性的向下调整算法
/// </summary>
/// <param name="val">存储堆数据的数组指针</param>
/// <param name="size">当前堆的大小</param>
/// <param name="i">当前堆顶的下标</param>
static void AdjustDown(HPDataType* val, int size, int i)
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
/// 堆的插入函数，尾插，插入后再调整数据，让数据保持堆的特性
/// </summary>
/// <param name="php">要插入的堆，传递堆结构体变量的指针</param>
/// <param name="val">要插入的值</param>
void HP_Push(HP* php, HPDataType val)
{
	assert(php);
	//空间不足扩容
	if (php->size >= php->capacity)
	{
		//capacity的值不为0时
		if (php->capacity)
		{
			php->capacity *= 2;
		}
		else
		{
			php->capacity = 4;
		}
		HPDataType* newHPDataType = (HPDataType*)realloc(php->val, sizeof(HPDataType) * php->capacity);
		if (newHPDataType == NULL)
		{
			perror("HP_Push:realloc");
			exit(1);
		}
		php->val = newHPDataType;
	}
	php->val[php->size++] = val;
	//向上调整算法：要让插入数据后保持堆的特性
	AdjustUp(php->val, php->size - 1);
}

/// <summary>
/// 返回堆顶的值
/// </summary>
/// <param name="php">要查看的堆结构体变量的指针</param>
/// <returns>堆顶的值，但是不弹出堆顶</returns>
HPDataType HP_Top(HP* php)
{
	assert(php);

	return php->val[0];
}

/// <summary>
/// 弹出堆顶
/// </summary>
/// <param name="php">要弹出的堆结构体变量的指针</param>
void HP_Pop(HP* php)
{
	assert(php);
	assert(php->size > 0);//要有数据才可以pop

	//先首尾交换
	Swap(&(php->val[0]), &(php->val[php->size - 1]));
	//删除尾值
	php->size--;
	//向下调整算法
	AdjustDown(php->val, HP_Size(php), 0);
}

/// <summary>
/// 判断指定堆是否为空
/// </summary>
/// <param name="php">要查看的堆结构体变量的指针</param>
/// <returns>返回真表示这个堆是空的，反之返回假就是不空</returns>
bool HP_Empty(HP* php)
{
	assert(php);

	return php->size == 0;
}

/// <summary>
/// 返回指定堆的大小
/// </summary>
/// <param name="php">要查看的堆结构体变量的指针</param>
/// <returns>指定堆的有效数据的个数</returns>
int HP_Size(HP* php)
{
	assert(php);

	return php->size;
}

void HP_InitArray(HP* php, HPDataType* arr, int size)
{
	php->val = (HPDataType*)malloc(sizeof(HPDataType) * size);
	if (php->val == NULL)
	{
		perror("HP_InitArray:malloc");
		exit(1);
	}
	memcpy(php->val, arr, sizeof(HPDataType) * size);
	php->capacity = php->size = size;

	////向上建堆
	//for (int i = 1; i < php->size; i++)
	//{
	//	AdjustUp(php->val, i);
	//}

	//向下建堆
	//向下调整的算法有一个要求，要求当前节点的左右子树都要满足堆的性质，只有当前节点不满足堆的性质
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->val, php->size, i);
	}
}

void HeapSort(int* a, int n)
{
	HP hp;
	HP_InitArray(&hp, a, n);
	//将堆顶数据依次弹出到数组中，此时如果是大堆就是降序，小堆就是升序
	int i = 0;
	while (!HP_Empty(&hp))
	{
		a[i++] = HP_Top(&hp);
		HP_Pop(&hp);
	}
	HP_Destroy(&hp);
}
