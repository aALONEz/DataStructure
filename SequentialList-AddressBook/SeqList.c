#include "SeqList.h"

/*
* ��������DSL_Init
* ��;���Զ�̬����˳�����г�ʼ��
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
* ����ֵ����
* ��ע����
*/
void DSL_Init(DynamicSeqList* pDSL)
{
	//�ж�ָ���Ƿ�ΪNULL
	assert(pDSL);
	pDSL->a = NULL;		//��ָ�븳ֵΪNULL
	pDSL->length = 0;	//��˳������Ч������ֵΪ0
	pDSL->capacity = 0;	//��˳�������ռ丳ֵΪ0
}

/*
* ��������DSL_CheckCapacity
* ��;���ж϶�̬˳����Ƿ���Ҫ����
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
* ����ֵ����
* ��ע����
*/
static void DSL_CheckCapacity(DynamicSeqList* pDSL)
{
	//�ж�ָ���Ƿ�ΪNULL
	assert(pDSL);
	//�ж���Ч���ݸ����ǲ��ǵ�������������������ô���ǿռ䲻����Ҫ����
	if (pDSL->length == pDSL->capacity)		//�������ж��ǲ�����Ҫ����
	{
		int new_capacity = pDSL->capacity == 0 ? 4 : 2 * pDSL->capacity;//���pDSL->capacity����0��ô���Ǹճ�ʼ�����������ʱ������������4�����������0����ô���������ݵ���û��ʣ��ռ��ˣ���ʱ����ֱ������2��
		SL_Data_Type* tmp = (SL_Data_Type*)realloc(pDSL->a, sizeof(SL_Data_Type) * new_capacity);
		if (tmp == NULL)
		{
			perror("��̬���ݳ�������\n");
			exit(1);						//����ʧ��ֱ���˳�
		}
		pDSL->a = tmp;
		pDSL->capacity = new_capacity;
		tmp = NULL;
	}
}

/*
* ��������DSL_PushBack
* ��;���Զ�̬����˳������β�������µ�����
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
*		x Ҫ��������ݣ�����ΪSL_Data_Type
* ����ֵ����
* ��ע����
*/
void DSL_PushBack(DynamicSeqList* pDSL, SL_Data_Type x)
{
	//�ж�ָ���Ƿ�ΪNULL
	assert(pDSL);
	//�ж��Ƿ���Ҫ����
	DSL_CheckCapacity(pDSL);
	//��������
	pDSL->a[pDSL->length++] = x;			//��β���������ݣ���������Ч���ݸ�����1
}

/*
* ��������DSL_PushFront
* ��;���Զ�̬����˳������ͷ�������µ�����
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
*		x Ҫ��������ݣ�����ΪSL_Data_Type
* ����ֵ����
* ��ע����
*/
void DSL_PushFront(DynamicSeqList* pDSL, SL_Data_Type x)
{
	assert(pDSL);
	//�ж��Ƿ���Ҫ����
	DSL_CheckCapacity(pDSL);
	//�����ݴӺ���ǰŲ��һλ
	for (int i = pDSL->length; i > 0; i--)
	{
		pDSL->a[i] = pDSL->a[i - 1];
	}
	pDSL->length++;
	//��ͷ����������
	pDSL->a[0] = x;
}

/*
* ��������DSL_CheckLength
* ��;���Զ�̬����˳�����Ч�����Ƿ�Ϊ0�����ж�
* ������pDSL DynamicSeqList����ָ�룬Ҫ�жϵ�˳���ָ��
* ����ֵ������1��ʾ��Ч������0		����0��ʾ��Ч����Ϊ0
* ��ע����
*/
static int DSL_CheckLength(DynamicSeqList* pDSL)
{
	//�ж���Ч���ݸ����Ƿ�Ϊ0
	if (pDSL->length == 0)
	{
		return 0;
	}
	return 1;
}

/*
* ��������DSL_PopBack
* ��;���Զ�̬����˳������β��ɾ��
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
* ����ֵ����
* ��ע����
*/
void DSL_PopBack(DynamicSeqList* pDSL)
{
	assert(pDSL);
	if (DSL_CheckLength(pDSL) == 0)
	{
		return;
	}
	//ֱ�ӽ���Ч������1
	pDSL->length--;
}

/*
* ��������DSL_PopFront
* ��;���Զ�̬����˳������ͷ��ɾ��
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
* ����ֵ����
* ��ע����
*/
void DSL_PopFront(DynamicSeqList* pDSL)
{
	assert(pDSL);
	if (DSL_CheckLength(pDSL) == 0)
	{
		return;
	}
	//��ǰ����ƶ�����
	for (int i = 0; i < pDSL->length - 1; i++)
	{
		pDSL->a[i] = pDSL->a[i + 1];
	}
	pDSL->length--;
}

/*
* ��������DSL_Insert
* ��;���Զ�̬����˳������ָ��λ�ò���
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
*		pos Ҫ���뵽�Ǹ��±�֮ǰ
*		x Ҫ��������ݣ�����ΪSL_Data_Type
* ����ֵ����
* ��ע����
*/
void DSL_Insert(DynamicSeqList* pDSL, int pos, SL_Data_Type x)
{
	assert(pDSL);
	//�ж�pos�Ƿ�������Ҳ�����ж�pos�Ƿ������Ч����
	if (pos > pDSL->length || pos < 0)
	{
		return;
	}
	DSL_CheckCapacity(pDSL);		//���ռ�
	for (int i = pDSL->length; i > pos; i--)
	{
		//�Ӻ���ǰ�ƶ�����
		pDSL->a[i] = pDSL->a[i - 1];
	}
	pDSL->a[pos] = x;				//posλ��Ԫ�ظ�ֵΪҪ�����ֵ
	pDSL->length++;					//��Ч������1
}

/*
* ��������DSL_Erase
* ��;���Զ�̬����˳������ָ��λ��ɾ��
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
*		pos Ҫɾ��Ԫ�ص��±�ֵ
* ����ֵ����
* ��ע����
*/
void DSL_Erase(DynamicSeqList* pDSL, int pos)
{
	assert(pDSL);
	if (pos >= pDSL->length || pos < 0)		//���Ҫɾ���������±�ֵ���ڵ�����Ч���ݸ����򷵻ء�
	{
		return;
	}
	for (int i = pos; i < pDSL->length - 1; i++)
	{
		pDSL->a[i] = pDSL->a[i + 1];
	}
	pDSL->length--;							//������Ч������1
}

/*
* ��������DSL_Find
* ��;���Զ�̬����˳������ָ��ֵ�Ĳ���
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
*		x Ҫ���ҵ�ֵ
* ����ֵ��δ�ҵ�����-1���ҵ��˷��ض�Ӧ���±꣬���Ŀ��ʱֻ���ذ���˳���һ�γ��ֵ��±�
* ��ע����
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
* ��������DSL_Destroy
* ��;���Զ�̬����˳����������
* ������pDSL DynamicSeqList����ָ�룬Ҫ���ٵ�˳���ָ��
* ����ֵ����
* ��ע����
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
* ��������DSL_Modify
* ��;���Զ�̬����˳������ָ��λ�õ�ֵ���޸�
* ������pDSL DynamicSeqList����ָ�룬Ҫ������˳���ָ��
*		pos Ҫ�޸��Ǹ��±��ֵ
*		x �޸ĺ��ֵ
* ����ֵ����
* ��ע����
*/
void DSL_Modify(DynamicSeqList* pDSL, int pos, SL_Data_Type x)
{
	assert(pDSL);
	if (pos >= pDSL->length || pos < 0)		//���Ҫ�޸ĵ������±�ֵ���ڵ�����Ч���ݸ����򷵻ء�
	{
		return;
	}
	pDSL->a[pos] = x;
}
