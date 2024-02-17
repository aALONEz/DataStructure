#include "AddressBook.h"
#include "SeqList.h"

void AddressBook_Menu(void)
{
	printf("--------------通讯录---------------\n");
	printf("---1.增加联系人   2.删除联系人-----\n");
	printf("---3.查找联系人   4.修改联系人-----\n");
	printf("---5.查看通讯录   0.退出通讯录-----\n");
	printf("-----------------------------------\n");
}

void AddressBook_Init(AddressBook_SL *pAddressBook)
{
	//调用顺序的初始化函数
	DSL_Init((DynamicSeqList*)pAddressBook);
}

void AddressBook_DesTroy(AddressBook_SL *pAddressBook)
{
	//调用顺序表的销毁函数
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