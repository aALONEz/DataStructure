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
	if (newSL_Node == NULL)
	{
		perror("�����½ڵ�ʧ�ܡ�mallocʧ�ܣ�\n");
		exit(1);
	}
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
void SingleList_Print(SingleListNode** const ppSL_Node, void SLPrint(void* data))
{
	SingleListNode *tmpSL_Node = *ppSL_Node;
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
void SingleList_PushBack(SingleListNode** const ppSL_Node, ListDataType x)//����Ҫ���ն���ָ�������Ǵ�ֵ��ֻ�д���ַ�ſ��Ըı���ָ�������
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
void SingleList_PushFront(SingleListNode** const ppSL_Node, ListDataType x)
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
void SingleList_PopBack(SingleListNode** const ppSL_Node)
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
void SingleList_PopFront(SingleListNode** const ppSL_Node)
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

/*
* ��������SingleList_Find
* ��;��������Ĳ��Һ�����
* ������ppSL_Node Ҫ�����ĵ������ͷ�ڵ�Ķ���ָ��
*		x Ҫ���ҵ�ֵ
* ����ֵ��δ�ҵ�����NULL���ҵ��ͷ������ڽڵ�ĵ�ַ
* ��ע����
*/
SingleListNode* SingleList_Find(SingleListNode** const ppSL_Node, ListDataType x)
{
	assert(ppSL_Node);
	SingleListNode* tmpSL_Node = *ppSL_Node;

	while (tmpSL_Node)//ֻҪ��ǰ�ڵ㲻Ϊ�վ�һֱѭ�������ڵ�
	{
		if (tmpSL_Node->data == x)//�����ǰ�ڵ������λ����Ҫ���ҵ�ֵ����ô�ͷ��ص�ǰ�ڵ�
		{
			return tmpSL_Node;
		}
		tmpSL_Node = tmpSL_Node->next;
	}
	return NULL;
}

/*
* ��������SingleList_Insert
* ��;���������ָ��λ��֮ǰ���뺯����
* ������ppSL_Node Ҫ�����ĵ������ͷ�ڵ�Ķ���ָ��
*		posSL_Node Ҫ���Ǹ�λ��֮ǰ�������ݣ��ڵ�ĵ�ַ
*		x Ҫ���������
* ����ֵ����
* ��ע����
*/
void SingleList_Insert(SingleListNode** const ppSL_Node, SingleListNode* const posSL_Node, ListDataType x)
{
	assert(ppSL_Node && posSL_Node && *ppSL_Node);
	SingleListNode* newSL_Node = NewNode(x);
	if (*ppSL_Node == posSL_Node)//�����������ͷ��֮ǰ�������ͷ��ֱ�ӵ���ͷ��
	{
		SingleList_PushFront(ppSL_Node, x);
		return;
	}
	SingleListNode* tmpSL_Node = *ppSL_Node;
	while (tmpSL_Node->next != posSL_Node)
	{
		tmpSL_Node = tmpSL_Node->next;
	}
	newSL_Node->next = posSL_Node;
	tmpSL_Node->next = newSL_Node;
}

/*
* ��������SingleList_InsertAfter
* ��;���������ָ��λ��֮����뺯����
* ������posSL_Node Ҫ���Ǹ�λ��֮��������ݣ��ڵ�ĵ�ַ
*		x Ҫ���������
* ����ֵ����
* ��ע����
*/
void SingleList_InsertAfter(SingleListNode *posSL_Node, ListDataType x)
{
	assert(posSL_Node);
	SingleListNode* newSL_Node = NewNode(x);		//�����½ڵ�
	newSL_Node->next = posSL_Node->next;
	posSL_Node->next = newSL_Node;
}

/*
* ��������SingleList_Erase
* ��;���������ָ��λ��ɾ���뺯����
* ������ppSL_Node Ҫ�����ĵ������ͷ�ڵ�Ķ���ָ��
*		posSL_Node ָ��λ�õĽڵ��ַ
* ����ֵ����
* ��ע����
*/
void SingleList_Erase(SingleListNode** const ppSL_Node, SingleListNode* posSL_Node)
{
	assert(posSL_Node && ppSL_Node && *ppSL_Node);

	
	if (*ppSL_Node == posSL_Node)//�������ָ������ͷ��ɾ������ô����ͷɾ��ֱ�ӵ���ͷɾ����
	{
		SingleList_PopFront(ppSL_Node);
		return;
	}
	SingleListNode* tmpSL_Node = *ppSL_Node;
	while (tmpSL_Node->next != posSL_Node)//���������ҵ�ָ��λ��ǰһ���ڵ�
	{
		tmpSL_Node = tmpSL_Node->next;
	}
	tmpSL_Node->next = posSL_Node->next;
	free(posSL_Node);
	posSL_Node = NULL;
}

/*
* ��������SingleList_InsertAfter
* ��;���������ָ��λ��֮����뺯����
* ������posSL_Node Ҫɾ���Ǹ�λ��֮������ݣ��ڵ�ĵ�ַ
* ����ֵ����
* ��ע����
*/
void SingleList_EraseAfter(SingleListNode* posSL_Node)
{
	assert(posSL_Node && posSL_Node->next);

	SingleListNode* tmpSL_Node = posSL_Node->next;
	posSL_Node->next = tmpSL_Node->next;
	free(tmpSL_Node);
	tmpSL_Node = NULL;
}

/*
* ��������SingleList_DesTroy
* ��;������������ٺ�����
* ������ppSL_Node Ҫ����������Ķ���ָ��
* ����ֵ����
* ��ע����
*/
void SingleList_DesTroy(SingleListNode** ppSL_Node)
{
	assert(ppSL_Node && *ppSL_Node);

	SingleListNode* nextSL_Node = (*ppSL_Node)->next;
	SingleListNode* tmpSL_Node = *ppSL_Node;

	while (tmpSL_Node)
	{
		nextSL_Node = tmpSL_Node->next;
		free(tmpSL_Node);
		tmpSL_Node = nextSL_Node;
	}
	*ppSL_Node = tmpSL_Node;
}