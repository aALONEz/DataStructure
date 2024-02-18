#include "SingleList.h"

/*
* ��������SLPrintInt
* ��;��������Ĵ�ӡ����������
* ������data Ҫ��ӡ��ֵ�ĵ�ַ
* ����ֵ����
* ��ע����
*/
void SLPrintInt(void *data)
{
	printf("%d->", *((int *)data));
}

/*
* ��������NewNode
* ��;��������������½ڵ㺯����
* ������x �½ڵ�����ݣ�Ҳ����data��Ա��ֵ
* ����ֵ���½ڵ�ĵ�ַ
* ��ע����
*/
static SingleListNode *NewNode(ListDataType x)
{
	SingleListNode *newSL_Node = (SingleListNode *)malloc(sizeof(SingleListNode));
	newSL_Node->data = x;
	newSL_Node->next = NULL;
	return newSL_Node;
}

/*
* ��������SingleList_Print
* ��;��������Ĵ�ӡ������
* ������pSL_Node Ҫ�����ĵ������ͷ�ڵ�ָ��
*		SLPrint ��ӡ������ָ�룬����ͷΪvoid SLPrint(void *data)
* ����ֵ����
* ��ע����
*/
void SingleList_Print(SingleListNode *pSL_Node, void SLPrint(void *data))
{
	SingleListNode *tmpSL_Node = pSL_Node;
	while (tmpSL_Node)
	{
		//��ӡ����
		SLPrint(&(tmpSL_Node->data));
		tmpSL_Node = tmpSL_Node->next;
	}
	printf("NULL\n");
}

/*
* ��������SingleList_PushBack
* ��;���������β�����뺯����
* ������ppSL_Node Ҫ�����ĵ������ͷ�ڵ�Ķ���ָ��
*		x Ҫ����Ľڵ�����
* ����ֵ����
* ��ע����
*/
void SingleList_PushBack(SingleListNode **ppSL_Node, ListDataType x)//����Ҫ���ն���ָ�������Ǵ�ֵ��ֻ�д���ַ�ſ��Ըı���ָ�������
{
	assert(ppSL_Node);
	//�����µĽڵ㲢��ֵ
	SingleListNode *newSL_Node = NewNode(x);//���������½ڵ�ֱ�ӽ������½ڵ��װΪһ������
	//û����Ч�ڵ�
	if (*ppSL_Node == NULL)
	{
		*ppSL_Node = newSL_Node;
		return;
	}
	//������Ч�ڵ�
	SingleListNode *tmpSL_Node = *ppSL_Node;
	while (tmpSL_Node->next)
	{
		tmpSL_Node = tmpSL_Node->next;
	}
	//����
	tmpSL_Node->next = newSL_Node;
}

/*
* ��������SingleList_PushBack
* ��;���������ͷ�����뺯����
* ������ppSL_Node Ҫ�����ĵ������ͷ�ڵ�Ķ���ָ��
*		x Ҫ����Ľڵ�����
* ����ֵ����
* ��ע����
*/
void SingleList_PushFront(SingleListNode **ppSL_Node, ListDataType x)
{
	assert(ppSL_Node);
	//�����µĽڵ㲢��ֵ
	SingleListNode *newSL_Node = NewNode(x);//���������½ڵ�ֱ�ӽ������½ڵ��װΪһ������
	newSL_Node->next = *ppSL_Node;	//���½ڵ��next��Ա��ֵ��ֵΪ��ǰͷ�ڵ�
	*ppSL_Node = newSL_Node;		//�ٽ�ͷ�ڵ㸳ֵΪnewSL_Node�ڵ�
}

/*
* ��������SingleList_PopBack
* ��;���������β��ɾ��������
* ������ppSL_Node Ҫ�����ĵ������ͷ�ڵ�Ķ���ָ��
* ����ֵ����
* ��ע����
*/
void SingleList_PopBack(SingleListNode **ppSL_Node)
{
	//������Ϊ��
	assert(ppSL_Node && *ppSL_Node);
	//�ж������ǲ���ֻ��һ���ڵ�
	if ((*ppSL_Node)->next == NULL)
	{
		free(*ppSL_Node);
		*ppSL_Node = NULL;
		return;
	}
	//����ڵ�
	SingleListNode *ptailSL_Node = *ppSL_Node;
	SingleListNode *prevSL_Node = NULL;
	while (ptailSL_Node->next)
	{
		prevSL_Node = ptailSL_Node;
		ptailSL_Node = ptailSL_Node->next;
	}
	//����β�ڵ�
	free(ptailSL_Node);
	ptailSL_Node = NULL;
	//���µ�β�ڵ��next��Ա����ΪNULL
	prevSL_Node->next = NULL;
}

/*
* ��������SingleList_PopFront
* ��;���������ͷ��ɾ��������
* ������ppSL_Node Ҫ�����ĵ������ͷ�ڵ�Ķ���ָ��
* ����ֵ����
* ��ע����
*/
void SingleList_PopFront(SingleListNode **ppSL_Node)
{
	//������Ϊ��
	assert(ppSL_Node && *ppSL_Node);
	//������ʱ�ڵ㣬�����¸��ڵ�ĵ�ַ
	SingleListNode *tmpSL_Node = (*ppSL_Node)->next;
	//�ͷ�ͷ���ڵ�
	free(*ppSL_Node);
	//����ָ��ͷ���ڵ��ַ
	*ppSL_Node = tmpSL_Node;
}