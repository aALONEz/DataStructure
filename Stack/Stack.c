#include "Stack.h"

/// <summary>
/// �ײ�Ϊ�����ջ��ʼ������
/// </summary>
/// <param name="pstack">Ҫ��ʼ����ջָ�룬Stack���͵Ľṹ��ָ��</param>
void ST_Init(ST* pstack)
{
	assert(pstack);

	pstack->a = NULL;
	pstack->capacity = 0;
	pstack->top = -1;//����ջ��ָ��Ӽ��ٲ������ݣ�topָʾ���ǵ�ǰջ��Ԫ�ص��±�
}

/// <summary>
/// �ײ�������ʵ�ֵ�ջ�����ٺ���
/// </summary>
/// <param name="pstack">Ҫ���ٵ�ջָ�룬Stack���͵Ľṹ��ָ��</param>
void ST_Destroy(ST* pstack)
{
	assert(pstack);

	free(pstack->a);
	pstack->a = NULL;
	pstack->capacity = 0;
	pstack->top = -1;
}

/// <summary>
/// �ײ�������ʵ�ֵ�ջ��ѹ���������
/// </summary>
/// <param name="pstack">Ҫѹ�������ջָ�룬Stack���͵Ľṹ��ָ��</param>
/// <param name="data">ѹ��ջ�����ݣ�STDataType����</param>
void ST_Push(ST* pstack, STDataType data)
{
	assert(pstack);

	//����
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
	//����ʵ��ѹ��Ҫβ�壬ͷ�������̫�󣬶���Ч�ʵ���
	pstack->top++;							//ջ��ָ���ȼӼ�
	pstack->a[pstack->top] = data;			//��ֵ
}

/// <summary>
/// �ײ�������ʵ�ֵ�ջ��������������
/// </summary>
/// <param name="pstack">Ҫ����ջ��Ԫ�ص�ջָ�룬Stack���ͽṹ��</param>
void ST_Pop(ST* pstack)
{
	assert(pstack);
	assert(!ST_Empty(pstack));//�ж�ջ�Ƿ�Ϊ��

	pstack->top--;
}

/// <summary>
/// �ײ�������ʵ�ֵ�ջ���鿴ջ��Ԫ�غ���
/// </summary>
/// <param name="pstack">Ҫ�鿴ջ��Ԫ�ص�ջָ�룬Stack���ͽṹ��</param>
/// <returns>���ص�ǰջ��Ԫ�أ����ǲ�������ǰջ��Ԫ��</returns>
STDataType ST_Top(ST* pstack)
{
	assert(pstack);

	return pstack->a[pstack->top];
}

/// <summary>
/// �ײ�������ʵ�ֵ�ջ���鿴��ǰջ��С�ĺ��������������鿴��ЧԪ�صĸ���
/// </summary>
/// <param name="pstack">Ҫ�鿴��ջָ�룬Stack���ͽṹ��</param>
/// <returns>��ǰջ��ЧԪ�ظ���</returns>
int ST_Size(ST* pstack)
{
	assert(pstack);

	return (pstack->top + 1);
}

/// <summary>
/// �ײ�������ʵ�ֵ�ջ���жϵ�ǰջ�ǲ���Ϊ�գ�Ҳ����������Ч����
/// </summary>
/// <param name="pstack">Ҫ�鿴�Ƿ�Ϊ�յ�ջָ�룬Stack���ͽṹ��</param>
/// <returns>Ϊ�շ��� true ���ǿշ���false</returns>
bool ST_Empty(ST* pstack)
{
	assert(pstack);

	return pstack->top <= -1;
}
