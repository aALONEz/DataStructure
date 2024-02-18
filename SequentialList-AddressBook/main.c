#include "SeqList.h"

int main()
{
	int option = -1;
	AddressBook_SL addressbook_sl;
	AddressBook_Init(&addressbook_sl);					//��ʼ��ͨѶ¼
	do
	{
		AddressBook_Menu();								//��ӡ�˵�
		printf("����������ѡ��");
		scanf("%d", &option);
		switch (option)
		{
			case 0:
			{
				//�˳�ͨѶ¼
				AddressBook_DesTroy(&addressbook_sl);	//����ͨѶ¼
				printf("�˳�ͨѶ¼��\n");
				break;
			}
			case 1:
			{
				//������ϵ��
				AddressBook_AddContacts(&addressbook_sl);
				break;
			}
			case 2:
			{
				//ɾ����ϵ��
				AddressBook_DelContacts(&addressbook_sl);
				break;
			}
			case 3:
			{
				//������ϵ��
				AddressBook_FindContacts(&addressbook_sl);
				break;
			}
			case 4:
			{
				//�޸���ϵ��
				AddressBook_ModifyContacts(&addressbook_sl);
				break;
			}
			case 5:
			{
				//�鿴ͨѶ¼
				AddressBook_ShowContacts(&addressbook_sl);
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