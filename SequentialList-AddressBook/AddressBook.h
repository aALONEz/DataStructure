#pragma once

#define NAME_MAX 20
#define TEL_MAX 12
#define ADDR_MAX 100



typedef enum
{
	male = 0,
	female = 1,
	NonBinary = 2,
}Gender;

typedef struct
{
	char name[NAME_MAX];	//��ϵ������
	Gender gender;			//��ϵ���Ա�
	int age;				//��ϵ������
	char tel[TEL_MAX];		//��ϵ�˵绰
	char addr[ADDR_MAX];	//��ϵ�˵�ַ
}Contacts;

struct SeqList;//ǰ������
typedef struct SeqList AddressBook_SL;

void AddressBook_Menu(void);
void AddressBook_Init(AddressBook_SL *pAddressBook);
void AddressBook_DesTroy(AddressBook_SL *pAddressBook);
void AddressBook_AddContacts(AddressBook_SL *pAddressBook);
void AddressBook_ModifyContacts(AddressBook_SL *pAddressBook);
void AddressBook_FindContacts(AddressBook_SL *pAddressBook);
void AddressBook_ShowContacts(AddressBook_SL *pAddressBook);
void AddressBook_DelContacts(AddressBook_SL *pAddressBook);
