#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "AddressBook.h"

int main()
{
	int option = -1;
	do
	{
		AddressBook_Menu();
		printf("请输入您的选择：");
		scanf("%d", &option);
		switch (option)
		{
			case 0:
			{
				//退出通讯录
				printf("退出通讯录！\n");
				break;
			}
			case 1:
			{
				//增加联系人
				break;
			}
			case 2:
			{
				//删除联系人
				break;
			}
			case 3:
			{
				//查找联系人
				break;
			}
			case 4:
			{
				//修改联系人
				break;
			}
			case 5:
			{
				//查看通讯录
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