#include "SeqList.h"

/*
* 函数名：DSL_Init
* 用途：对动态申请顺序表进行初始化
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
* 返回值：无
* 备注：无
*/
void DSL_Init(DynamicSeqList* pDSL)
{
	//判断指针是否为NULL
	assert(pDSL);
	pDSL->a = NULL;		//将指针赋值为NULL
	pDSL->length = 0;	//将顺序表的有效个数赋值为0
	pDSL->capacity = 0;	//将顺序表的最大空间赋值为0
}

/*
* 函数名：DSL_CheckCapacity
* 用途：判断动态顺序表是否需要扩容
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
* 返回值：无
* 备注：无
*/
static void DSL_CheckCapacity(DynamicSeqList* pDSL)
{
	//判断指针是否为NULL
	assert(pDSL);
	//判断有效数据个数是不是等于最大个数，如果相等那么就是空间不足需要扩容
	if (pDSL->length == pDSL->capacity)		//在这里判断是不是需要扩容
	{
		int new_capacity = pDSL->capacity == 0 ? 4 : 2 * pDSL->capacity;//如果pDSL->capacity等于0那么就是刚初始化的情况，此时新最大个数就是4，如果不等于0，那么就是有数据但是没有剩余空间了，此时就是直接扩容2倍
		SL_Data_Type* tmp = (SL_Data_Type*)realloc(pDSL->a, sizeof(SL_Data_Type) * new_capacity);
		if (tmp == NULL)
		{
			perror("动态扩容出错！！！\n");
			exit(1);						//扩容失败直接退出
		}
		pDSL->a = tmp;
		pDSL->capacity = new_capacity;
		tmp = NULL;
	}
}

/*
* 函数名：DSL_PushBack
* 用途：对动态申请顺序表进行尾部插入新的数据
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
*		x 要插入的数据，类型为SL_Data_Type
* 返回值：无
* 备注：无
*/
void DSL_PushBack(DynamicSeqList* pDSL, SL_Data_Type x)
{
	//判断指针是否为NULL
	assert(pDSL);
	//判断是否需要扩容
	DSL_CheckCapacity(pDSL);
	//插入数据
	pDSL->a[pDSL->length++] = x;			//在尾部插入数据，并且让有效数据个数加1
}

/*
* 函数名：DSL_PushFront
* 用途：对动态申请顺序表进行头部插入新的数据
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
*		x 要插入的数据，类型为SL_Data_Type
* 返回值：无
* 备注：无
*/
void DSL_PushFront(DynamicSeqList* pDSL, SL_Data_Type x)
{
	assert(pDSL);
	//判断是否需要扩容
	DSL_CheckCapacity(pDSL);
	//旧数据从后向前挪动一位
	for (int i = pDSL->length; i > 0; i--)
	{
		pDSL->a[i] = pDSL->a[i - 1];
	}
	pDSL->length++;
	//在头部插入数据
	pDSL->a[0] = x;
}

/*
* 函数名：DSL_CheckLength
* 用途：对动态申请顺序表有效个数是否为0进行判断
* 参数：pDSL DynamicSeqList类型指针，要判断的顺序表指针
* 返回值：返回1表示有效个数非0		返回0表示有效个数为0
* 备注：无
*/
static int DSL_CheckLength(DynamicSeqList* pDSL)
{
	//判断有效数据个数是否为0
	if (pDSL->length == 0)
	{
		return 0;
	}
	return 1;
}

/*
* 函数名：DSL_PopBack
* 用途：对动态申请顺序表进行尾部删除
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
* 返回值：无
* 备注：无
*/
void DSL_PopBack(DynamicSeqList* pDSL)
{
	assert(pDSL);
	if (DSL_CheckLength(pDSL) == 0)
	{
		return;
	}
	//直接将有效个数减1
	pDSL->length--;
}

/*
* 函数名：DSL_PopFront
* 用途：对动态申请顺序表进行头部删除
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
* 返回值：无
* 备注：无
*/
void DSL_PopFront(DynamicSeqList* pDSL)
{
	assert(pDSL);
	if (DSL_CheckLength(pDSL) == 0)
	{
		return;
	}
	//从前向后移动数据
	for (int i = 0; i < pDSL->length - 1; i++)
	{
		pDSL->a[i] = pDSL->a[i + 1];
	}
	pDSL->length--;
}

/*
* 函数名：DSL_Insert
* 用途：对动态申请顺序表进行指定位置插入
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
*		pos 要插入到那个下标之前
*		x 要插入的数据，类型为SL_Data_Type
* 返回值：无
* 备注：无
*/
void DSL_Insert(DynamicSeqList* pDSL, int pos, SL_Data_Type x)
{
	assert(pDSL);
	//判断pos是否不连续，也就是判断pos是否大于有效个数
	if (pos > pDSL->length || pos < 0)
	{
		return;
	}
	DSL_CheckCapacity(pDSL);		//检查空间
	for (int i = pDSL->length; i > pos; i--)
	{
		//从后向前移动数据
		pDSL->a[i] = pDSL->a[i - 1];
	}
	pDSL->a[pos] = x;				//pos位置元素赋值为要插入的值
	pDSL->length++;					//有效个数加1
}

/*
* 函数名：DSL_Erase
* 用途：对动态申请顺序表进行指定位置删除
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
*		pos 要删除元素的下标值
* 返回值：无
* 备注：无
*/
void DSL_Erase(DynamicSeqList* pDSL, int pos)
{
	assert(pDSL);
	if (pos >= pDSL->length || pos < 0)		//如果要删除的数据下标值大于等于有效数据个数则返回。
	{
		return;
	}
	for (int i = pos; i < pDSL->length - 1; i++)
	{
		pDSL->a[i] = pDSL->a[i + 1];
	}
	pDSL->length--;							//数据有效个数减1
}

/*
* 函数名：DSL_Find
* 用途：对动态申请顺序表进行指定值的查找
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
*		x 要查找的值
* 返回值：未找到返回-1，找到了返回对应的下标，多个目标时只返回按照顺序第一次出现的下标
* 备注：无
*/
int DSL_Find(DynamicSeqList* pDSL, SL_Data_Type x)
{
	assert(pDSL);
	for (int i = 0; i < pDSL->length; i++)
	{
		/*if (pDSL->a[i] == x)
		{
			return i;
		}*/
	}
	return -1;
}

/*
* 函数名：DSL_Destroy
* 用途：对动态申请顺序表进行销毁
* 参数：pDSL DynamicSeqList类型指针，要销毁的顺序表指针
* 返回值：无
* 备注：无
*/
void DSL_DesTroy(DynamicSeqList* pDSL)
{
	assert(pDSL);
	if (pDSL->a != NULL)
	{
		free(pDSL->a);
		pDSL->a = NULL;
	}
	pDSL->length = 0;
	pDSL->capacity = 0;
}

/*
* 函数名：DSL_Modify
* 用途：对动态申请顺序表进行指定位置的值的修改
* 参数：pDSL DynamicSeqList类型指针，要操作的顺序表指针
*		pos 要修改那个下标的值
*		x 修改后的值
* 返回值：无
* 备注：无
*/
void DSL_Modify(DynamicSeqList* pDSL, int pos, SL_Data_Type x)
{
	assert(pDSL);
	if (pos >= pDSL->length || pos < 0)		//如果要修改的数据下标值大于等于有效数据个数则返回。
	{
		return;
	}
	pDSL->a[pos] = x;
}
