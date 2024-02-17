#pragma once
#include <stdlib.h>
#include <stdio.h>
struct DynamicSeqList;//ǰ������

#define NAME_MAX 20
#define TEL_MAX 12
#define ADDR_MAX 100

typedef struct DynamicSeqList AddressBook_SL;


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

void AddressBook_Menu(void);
void AddressBook_Init(AddressBook_SL *pAddressBook);
void AddressBook_DesTroy(AddressBook_SL *pAddressBook);
void AddressBook_AddContacts(AddressBook_SL *pAddressBook);
void AddressBook_ModifyContacts(AddressBook_SL *pAddressBook);
void AddressBook_FindContacts(AddressBook_SL *pAddressBook);
void AddressBook_ShowContacts(AddressBook_SL *pAddressBook);
