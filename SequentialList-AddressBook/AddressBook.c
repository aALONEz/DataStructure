#include "AddressBook.h"
#include "SeqList.h"

/*
* ��������AddressBook_Menu
* ��;��ͨѶ¼˳������ʾ�˵����溯��
* ��������
* ����ֵ����
* ��ע����
*/
void AddressBook_Menu(void)
{
	printf("--------------ͨѶ¼---------------\n");
	printf("---1.������ϵ��   2.ɾ����ϵ��-----\n");
	printf("---3.������ϵ��   4.�޸���ϵ��-----\n");
	printf("---5.�鿴ͨѶ¼   0.�˳�ͨѶ¼-----\n");
	printf("-----------------------------------\n");
}

/*
* ��������Input_Contacts
* ��;��ͨѶ¼˳����������ϵ����Ϣ����
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
* ����ֵ����
* ��ע��ֻ�ڱ��ļ��п��Ե���
*/
static void Input_Contacts(Contacts *contacts)
{
	printf("��������ϵ��������");
	scanf("%s", contacts->name);
	printf("\n��������ϵ���Ա�0.��ʾ���ԣ�1.��ʾŮ�ԣ�2.��ʾ�Ƕ�Ԫ�Ա𣩣�");
	scanf("%d", &(contacts->gender));
	printf("\n��������ϵ�����䣺");
	scanf("%d", &(contacts->age));
	printf("\n��������ϵ�˵绰��");
	scanf("%s", contacts->tel);
	printf("\n��������ϵ�˵�ַ��");
	scanf("%s", contacts->addr);
}

/*
* ��������Print_Contacts
* ��;��ͨѶ¼˳���Ĵ�ӡ��ϵ����Ϣ����
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
*		pos Ҫ��ӡpos�±����ϵ����Ϣ
* ����ֵ����
* ��ע��ֻ�ڱ��ļ��п��Ե���
*/
static void Print_Contacts(AddressBook_SL *pAddressBook, int pos)
{
	assert(pAddressBook);
	char gender[11];
	//�ж��Ա�ö�ٵ�ֵ
	switch (pAddressBook->a[pos].gender)
	{
		case 0:
		{
			strcpy(gender, "��");
			break;
		}
		case 1:
		{
			strcpy(gender, "Ů");
			break;
		}
		default:
		{
			strcpy(gender, "�Ƕ�Ԫ�Ա�");
			break;
		}
	}
	printf("%8s %15s %9d %18s     %s", pAddressBook->a[pos].name, gender, pAddressBook->a[pos].age, pAddressBook->a[pos].tel, pAddressBook->a[pos].addr);
	printf("\n");
}

/*
* ��������FindByName
* ��;��������ϵ���������Һ���
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
*		name Ҫ���ҵ�������char*���͵�
* ����ֵ������-1��ʾû���ҵ����ҵ��˷��ض�Ӧ���±�
* ��ע��ֻ�ڱ��ļ��п��Ե���
*/
static int FindByName(AddressBook_SL *pAddressBook, char *name)
{
	for (int i = 0; i < pAddressBook->length; i++)
	{
		if ((strcmp(pAddressBook->a[i].name, name)) == 0)
		{
			return i;
		}
	}
	return -1;
}

/*
* ��������AddressBook_Init
* ��;��ͨѶ¼˳���ĳ�ʼ������
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
* ����ֵ����
* ��ע����
*/
void AddressBook_Init(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	//����˳��ĳ�ʼ������
	DSL_Init(pAddressBook);
}

/*
* ��������AddressBook_DesTroy
* ��;��ͨѶ¼˳�������ٺ���
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
* ����ֵ����
* ��ע����
*/
void AddressBook_DesTroy(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	//����˳�������ٺ���
	DSL_DesTroy(pAddressBook);
}

/*
* ��������AddressBook_AddContacts
* ��;��ͨѶ¼˳���������ϵ�˺���
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
* ����ֵ����
* ��ע����
*/
void AddressBook_AddContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	//������ϵ�˽ṹ����������Ҹ�ֵ
	Contacts contacts;
	Input_Contacts(&contacts);
	//����ϵ�˽ṹ��������뵽ͨѶ¼��˳�����
	DSL_PushBack(pAddressBook, contacts);
}

/*
* ��������AddressBook_DelContacts
* ��;��ͨѶ¼˳����ɾ��ָ����ϵ�˺���
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
* ����ֵ����
* ��ע����
*/
void AddressBook_DelContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	char name[100];
	int num;
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", name);
	//��ɾ��֮ǰҪ�Ȳ��������ϵ���Ƿ����
	num = FindByName(pAddressBook, name);
	if (num < 0)
	{
		printf("û�������ϵ�ˣ������Ƿ��������ޣ�\n");
		return;
	}
	printf("\n");
	Print_Contacts(pAddressBook, num);
	char check;
	printf("\n������Yȷ��ɾ���������Y��ȡ����");
	getchar();
	scanf("%c", &check);
	if (check == 'Y' || check == 'y')
	{
		printf("ɾ���ɹ���\n");
		DSL_Erase(pAddressBook, num);
	}
}

/*
* ��������AddressBook_ModifyContacts
* ��;��ͨѶ¼˳�����޸�ָ����ϵ����Ϣ����
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
* ����ֵ����
* ��ע����
*/
void AddressBook_ModifyContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	//���޸�֮ǰҪ�Ȳ��������ϵ���Ƿ����
	char name[100];
	int num;
	printf("������Ҫ�޸���ϵ�˵�������");
	scanf("%s", name);
	//��ɾ��֮ǰҪ�Ȳ��������ϵ���Ƿ����
	num = FindByName(pAddressBook, name);
	if (num < 0)
	{
		printf("û�������ϵ�ˣ������Ƿ��������ޣ�\n");
		return;
	}
	printf("\n");
	Print_Contacts(pAddressBook, num);
	getchar();

	//������ϵ�˽ṹ����������Ҹ�ֵ
	Contacts contacts;
	Input_Contacts(&contacts);

	//�޸�ԭ����ֵ
	DSL_Modify(pAddressBook, num, contacts);
}

/*
* ��������AddressBook_FindContacts
* ��;��ͨѶ¼˳���Ĳ���ָ����ϵ�˺���
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
* ����ֵ����
* ��ע����
*/
void AddressBook_FindContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	char name[100];
	int num;
	printf("������Ҫ������ϵ�˵�������");
	scanf("%s", name);
	num = FindByName(pAddressBook, name);
	if (num < 0)
	{
		printf("û�������ϵ�ˣ������Ƿ��������ޣ�\n");
		return;
	}
	printf("\n");
	Print_Contacts(pAddressBook, num);
}

/*
* ��������AddressBook_ShowContacts
* ��;��ͨѶ¼˳���Ĳ鿴������ϵ�˺���
* ������pAddressBook һ��AddressBook_SL���͵�ָ�룬Ҫ������ͨѶ¼˳���
* ����ֵ����
* ��ע����
*/
void AddressBook_ShowContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	printf("��ϵ������----��ϵ���Ա�----��ϵ������----��ϵ�˵绰------��ϵ�˵�ַ\n");
	if (pAddressBook->length == 0)
	{
		return;
	}
	for (int i = 0; i < pAddressBook->length; i++)
	{
		Print_Contacts(pAddressBook, i);
	}
}