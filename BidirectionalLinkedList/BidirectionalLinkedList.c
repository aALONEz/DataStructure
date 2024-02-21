#include "BidirectionalLinkedList.h"

/*
* ��������NewNode
* ��;��˫�����������½ڵ㺯����
* ������data �½ڵ������λ��ֵ��
* ����ֵ���½ڵ��ָ��
* ��ע���κ���ֻ�ɱ��ļ����á�
*/
static BLL_Node* NewNode(BLL_DataType data)
{
	BLL_Node* tmpNode = (BLL_Node*)malloc(sizeof(BLL_Node));
	if (tmpNode == NULL)
	{
		perror("malloc����\n");
		exit(1);
	}
	tmpNode->data = data;
	(tmpNode)->next = (tmpNode);
	(tmpNode)->prev = (tmpNode);
	return tmpNode;
}

/*
* ��������BLL_Init
* ��;��˫�������ʼ����
* ��������
* ����ֵ��ͷ�ڵ��ָ��
* ��ע����
*/
BLL_Node* BLL_Init(void)
{
	return NewNode(0);
}

/*
* ��������BLL_PushBack
* ��;��˫�������β�庯����
* ������phead Ҫ������������ڱ��ڵ�ĵ�ַ
*		data Ҫ���������
* ����ֵ����
* ��ע����
*/
void BLL_PushBack(BLL_Node* phead, BLL_DataType data)
{
	//�ж��ڱ��ڵ㲻����Ϊ��
	assert(phead);
	//�����µĽڵ�
	BLL_Node* newNode = NewNode(data);
	//����β�ڵ�
	newNode->next = phead;
	newNode->prev = (phead->prev);
	(phead->prev)->next = newNode;
	phead->prev = newNode;
	
}

/*
* ��������BLL_PushFront
* ��;��˫�������ͷ�庯����
* ������phead Ҫ������������ڱ��ڵ�ĵ�ַ
*		data Ҫ���������
* ����ֵ����
* ��ע����
*/
void BLL_PushFront(BLL_Node* phead, BLL_DataType data)
{
	//�ж��ڱ��ڵ㲻ΪNULL
	assert(phead);
	//�����½ڵ�
	BLL_Node* newNode = NewNode(data);
	//ͷ���½ڵ�
	newNode->prev = phead;
	newNode->next = phead->next;
	(phead->next)->prev = newNode;
	phead->next = newNode;
}

/*
* ��������BLL_Print
* ��;��˫������Ĵ�ӡ������
* ������phead Ҫ������������ڱ��ڵ�ĵ�ַ
* ����ֵ����
* ��ע����
*/
void BLL_Print(BLL_Node* phead)
{
	//�ж��ڱ��ڵ㲻ΪNULL
	assert(phead);
	//����һ���ڱ��ڵ�
	BLL_Node* tmpNode = phead;
	while (tmpNode->next != phead)
	{
		tmpNode = tmpNode->next;//���õ�ǰ�ڵ��ƶ�����һ���ڵ㣬��Ϊͷ�ڵ���û�����ݵ�
		printf("%d->", tmpNode->data);
	}
	printf("ͷ�ڵ�\n");
}

/*
* ��������BLL_PopBack
* ��;��˫�������βɾ������
* ������phead Ҫ������������ڱ��ڵ�ĵ�ַ
* ����ֵ����
* ��ע����
*/
void BLL_PopBack(BLL_Node* phead)
{
	//�ж��ڱ��ڵ㲻ΪNULL
	assert(phead);
	//�ж�������������Ч�ڵ�
	if (phead->next == phead)
	{
		perror("βɾ��������Ч�ڵ�\n");
		exit(1);
	}
	//������ʱ�ڵ㣬���浱ǰβ�ڵ�
	BLL_Node* tmpNode = phead->prev;
	//�ڱ��ڵ����������µ�β�ڵ�
	phead->prev = tmpNode->prev;
	(tmpNode->prev)->next = phead;

	free(tmpNode);
	tmpNode = NULL;
}

/*
* ��������BLL_PopFront
* ��;��˫�������ͷɾ������
* ������phead Ҫ������������ڱ��ڵ�ĵ�ַ
* ����ֵ����
* ��ע����
*/
void BLL_PopFront(BLL_Node* phead)
{
	//�ж��ڱ��ڵ㲻ΪNULL
	assert(phead);
	//�ж�������������Ч�ڵ�
	if (phead->next == phead)
	{
		perror("ͷɾ��������Ч�ڵ�\n");
		exit(1);
	}
	//������ʱ�ڵ㣬���浱ǰ��һ����Ч�ڵ�
	BLL_Node* tmpNode = phead->next;
	//�������ӽڵ�
	phead->next = tmpNode->next;
	(tmpNode->next)->prev = phead;

	free(tmpNode);
	tmpNode = NULL;
}

/*
* ��������BLL_Find
* ��;��˫������Ĳ��Һ�����
* ������phead Ҫ������������ڱ��ڵ�ĵ�ַ
*		data Ҫ���ҵ�ֵ
* ����ֵ���������ֵ�Ľڵ�
* ��ע����
*/
BLL_Node* BLL_Find(BLL_Node* phead, BLL_DataType data)
{
	assert(phead);
	BLL_Node* tmpNode = phead->next;
	while (tmpNode != phead)
	{
		if (data == tmpNode->data)
		{
			return tmpNode;
		}
		tmpNode = tmpNode->next;
	}
	return NULL;
}

/*
* ��������BLL_Insert
* ��;��˫�������ָ��λ��֮��������ݵĺ�����
* ������posNode ָ���Ľڵ�ָ��
*		data Ҫ���������
* ����ֵ����
* ��ע����
*/
void BLL_Insert(BLL_Node* posNode, BLL_DataType data)
{
	assert(posNode);

	BLL_Node* newNode = NewNode(data);

	newNode->next = posNode->next;
	newNode->prev = posNode;
	(posNode->next)->prev = newNode;
	posNode->next = newNode;
}

/*
* ��������BLL_Erase
* ��;��˫�������ָ��λ��ɾ�����ݵĺ�����
* ������posNode ָ���Ľڵ�ָ��
* ����ֵ����
* ��ע����
*/
void BLL_Erase(BLL_Node* posNode)
{
	assert(posNode);

	BLL_Node* tmpNode = posNode;
	(tmpNode->next)->prev = tmpNode->prev;
	(tmpNode->prev)->next = tmpNode->next;

	free(tmpNode);
	tmpNode = NULL;
}

///*
//* ��������BLL_DesTroy
//* ��;��˫����������ٺ�����
//* ������pphead Ҫ���ٵ�����Ķ���ָ��
//* ����ֵ����
//* ��ע����
//*/
//void BLL_DesTroy(BLL_Node** pphead)
//{
//	assert(pphead);
//	assert(*pphead);
//
//	BLL_Node* tmpNode = (*pphead)->next;
//	
//	while (tmpNode != (*pphead))
//	{
//		BLL_Node* nextNode = tmpNode->next;
//		free(tmpNode);
//		tmpNode = nextNode;
//	}
//	free(*pphead);
//	*pphead = NULL;//���ڱ��ڵ���ΪNULL
//}

/*
* ��������BLL_DesTroy
* ��;��˫����������ٺ�����
* ������phead Ҫ���ٵ������ָ��
* ����ֵ����
* ��ע����
*/
void BLL_DesTroy(BLL_Node* phead)
{
	assert(phead);

	BLL_Node* tmpNode = phead->next;

	while (tmpNode != phead)
	{
		BLL_Node* nextNode = tmpNode->next;
		free(tmpNode);
		tmpNode = nextNode;
	}
	free(phead);
}