#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "AddressBook.h"

int main()
{
	int option = -1;
	do
	{
		AddressBook_Menu();
		printf("����������ѡ��");
		scanf("%d", &option);
		switch (option)
		{
			case 0:
			{
				//�˳�ͨѶ¼
				printf("�˳�ͨѶ¼��\n");
				break;
			}
			case 1:
			{
				//������ϵ��
				break;
			}
			case 2:
			{
				//ɾ����ϵ��
				break;
			}
			case 3:
			{
				//������ϵ��
				break;
			}
			case 4:
			{
				//�޸���ϵ��
				break;
			}
			case 5:
			{
				//�鿴ͨѶ¼
				break;
			}
			default:
			{
				printf("ѡ�����������ѡ��\n");
				break;
			}

		}
	} while (option != 0);
	return 0;
}