#include "SeqList.h"

int main()
{
	int option = -1;
	AddressBook_SL addressbook_sl;
	AddressBook_Init(&addressbook_sl);					//初始化通讯录
	do
	{
		AddressBook_Menu();								//打印菜单
		printf("请输入您的选择：");
		scanf("%d", &option);
		switch (option)
		{
			case 0:
			{
				//退出通讯录
				AddressBook_DesTroy(&addressbook_sl);	//销毁通讯录
				printf("退出通讯录！\n");
				break;
			}
			case 1:
			{
				//增加联系人
				AddressBook_AddContacts(&addressbook_sl);
				break;
			}
			case 2:
			{
				//删除联系人
				AddressBook_DelContacts(&addressbook_sl);
				break;
			}
			case 3:
			{
				//查找联系人
				AddressBook_FindContacts(&addressbook_sl);
				break;
			}
			case 4:
			{
				//修改联系人
				AddressBook_ModifyContacts(&addressbook_sl);
				break;
			}
			case 5:
			{
				//查看通讯录
				AddressBook_ShowContacts(&addressbook_sl);
				break;
			}
			default:
			{
				printf("选择错误，请重新选择！\n");
				break;
			}

		}
	} while (option != 0);
	return 0;
}