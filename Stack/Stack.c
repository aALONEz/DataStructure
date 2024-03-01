#include "Stack.h"

/// <summary>
/// 底层为数组的栈初始化函数
/// </summary>
/// <param name="pstack">要初始化的栈指针，Stack类型的结构体指针</param>
void ST_Init(ST* pstack)
{
	assert(pstack);

	pstack->a = NULL;
	pstack->capacity = 0;
	pstack->top = -1;//先让栈顶指针加加再插入数据，top指示的是当前栈顶元素的下标
}

/// <summary>
/// 底层是数组实现的栈的销毁函数
/// </summary>
/// <param name="pstack">要销毁的栈指针，Stack类型的结构体指针</param>
void ST_Destroy(ST* pstack)
{
	assert(pstack);

	free(pstack->a);
	pstack->a = NULL;
	pstack->capacity = 0;
	pstack->top = -1;
}

/// <summary>
/// 底层是数组实现的栈，压入操作函数
/// </summary>
/// <param name="pstack">要压入操作的栈指针，Stack类型的结构体指针</param>
/// <param name="data">压入栈的数据，STDataType类型</param>
void ST_Push(ST* pstack, STDataType data)
{
	assert(pstack);

	//扩容
	if (pstack->capacity - pstack->top == 1)
	{
		if (pstack->capacity == 0)
		{
			pstack->capacity += 4;
		}
		else
		{
			pstack->capacity *= 2;
		}
		STDataType* tmp = (STDataType*)realloc(pstack->a, sizeof(STDataType) * pstack->capacity);
		if (tmp == NULL)
		{
			perror("ST_Push:realloc");
			return;
		}
		pstack->a = tmp;
	}
	//数组实现压入要尾插，头插操作量太大，而且效率低下
	pstack->top++;							//栈顶指针先加加
	pstack->a[pstack->top] = data;			//赋值
}

/// <summary>
/// 底层是数组实现的栈，弹出操作函数
/// </summary>
/// <param name="pstack">要弹出栈顶元素的栈指针，Stack类型结构体</param>
void ST_Pop(ST* pstack)
{
	assert(pstack);
	assert(!ST_Empty(pstack));//判断栈是否为空

	pstack->top--;
}

/// <summary>
/// 底层是数组实现的栈，查看栈顶元素函数
/// </summary>
/// <param name="pstack">要查看栈顶元素的栈指针，Stack类型结构体</param>
/// <returns>返回当前栈顶元素，但是不弹出当前栈顶元素</returns>
STDataType ST_Top(ST* pstack)
{
	assert(pstack);

	return pstack->a[pstack->top];
}

/// <summary>
/// 底层是数组实现的栈，查看当前栈大小的函数，仅仅用来查看有效元素的个数
/// </summary>
/// <param name="pstack">要查看的栈指针，Stack类型结构体</param>
/// <returns>当前栈有效元素个数</returns>
int ST_Size(ST* pstack)
{
	assert(pstack);

	return (pstack->top + 1);
}

/// <summary>
/// 底层是数组实现的栈，判断当前栈是不是为空，也就是有无有效数据
/// </summary>
/// <param name="pstack">要查看是否为空的栈指针，Stack类型结构体</param>
/// <returns>为空返回 true ，非空返回false</returns>
bool ST_Empty(ST* pstack)
{
	assert(pstack);

	return pstack->top <= -1;
}
