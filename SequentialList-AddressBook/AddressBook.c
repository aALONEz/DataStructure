#include "AddressBook.h"
#include "SeqList.h"

void AddressBook_Menu(void)
{
	printf("--------------ͨѶ¼---------------\n");
	printf("---1.������ϵ��   2.ɾ����ϵ��-----\n");
	printf("---3.������ϵ��   4.�޸���ϵ��-----\n");
	printf("---5.�鿴ͨѶ¼   0.�˳�ͨѶ¼-----\n");
	printf("-----------------------------------\n");
}

void AddressBook_Init(AddressBook_SL *pAddressBook)
{
	//����˳��ĳ�ʼ������
	DSL_Init((DynamicSeqList*)pAddressBook);
}

void AddressBook_DesTroy(AddressBook_SL *pAddressBook)
{
	//����˳�������ٺ���
	DSL_DesTroy((DynamicSeqList *)pAddressBook);
}

void AddressBook_AddContacts(AddressBook_SL *pAddressBook)
{

}

void AddressBook_DelContacts(AddressBook_SL *pAddressBook)
{

}

void AddressBook_ModifyContacts(AddressBook_SL *pAddressBook)
{

}

void AddressBook_FindContacts(AddressBook_SL *pAddressBook)
{

}

void AddressBook_ShowContacts(AddressBook_SL *pAddressBook)
{

}