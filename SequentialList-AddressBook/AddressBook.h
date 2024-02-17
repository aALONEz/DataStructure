#pragma once
#include <stdlib.h>
#include <stdio.h>
struct DynamicSeqList;//前置声明

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
	char name[NAME_MAX];	//联系人姓名
	Gender gender;			//联系人性别
	int age;				//联系人年龄
	char tel[TEL_MAX];		//联系人电话
	char addr[ADDR_MAX];	//联系人地址
}Contacts;

void AddressBook_Menu(void);
void AddressBook_Init(AddressBook_SL *pAddressBook);
void AddressBook_DesTroy(AddressBook_SL *pAddressBook);
void AddressBook_AddContacts(AddressBook_SL *pAddressBook);
void AddressBook_ModifyContacts(AddressBook_SL *pAddressBook);
void AddressBook_FindContacts(AddressBook_SL *pAddressBook);
void AddressBook_ShowContacts(AddressBook_SL *pAddressBook);
