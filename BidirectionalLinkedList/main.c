#include "BidirectionalLinkedList.h"

int main()
{
	BLL_Node* phead = BLL_Init();

	//β��
	BLL_PushBack(phead, 1);
	BLL_PushBack(phead, 2);
	BLL_PushBack(phead, 5);

	//ͷ��
	BLL_PushFront(phead, 3);
	BLL_PushFront(phead, 4);

	//βɾ
	BLL_PopBack(phead);
	BLL_PopBack(phead);

	//ͷɾ
	BLL_PopFront(phead);
	BLL_PopFront(phead);

	//���ҽڵ�
	if (BLL_Find(phead, 5))
	{
		printf("�ҵ��ˣ�\n");
	}
	else
	{
		printf("δ�ҵ���\n");
	}

	//ָ��λ��֮���������
	BLL_Insert(BLL_Find(phead, 1), 8);

	//ָ��λ��ɾ������
	BLL_Erase(BLL_Find(phead, 8));

	//��ӡ����
	BLL_Print(phead);

	//��������
	//BLL_DesTroy(&phead);
	BLL_DesTroy(phead);
	phead = NULL;

	if (phead == NULL)
	{
		printf("�ڱ��ڵ������٣�\n");
	}
	else
	{
		printf("�ڱ��ڵ����ٳ���\n");
	}

	return 0;
}