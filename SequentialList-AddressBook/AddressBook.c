#include "AddressBook.h"
#include "SeqList.h"

/*
* 函数名：AddressBook_Menu
* 用途：通讯录顺序表的显示菜单界面函数
* 参数：无
* 返回值：无
* 备注：无
*/
void AddressBook_Menu(void)
{
	printf("--------------通讯录---------------\n");
	printf("---1.增加联系人   2.删除联系人-----\n");
	printf("---3.查找联系人   4.修改联系人-----\n");
	printf("---5.查看通讯录   0.退出通讯录-----\n");
	printf("-----------------------------------\n");
}

/*
* 函数名：Input_Contacts
* 用途：通讯录顺序表的输入联系人信息函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
* 返回值：无
* 备注：只在本文件中可以调用
*/
static void Input_Contacts(Contacts *contacts)
{
	printf("请输入联系人姓名：");
	scanf("%s", contacts->name);
	printf("\n请输入联系人性别（0.表示男性，1.表示女性，2.表示非二元性别）：");
	scanf("%d", &(contacts->gender));
	printf("\n请输入联系人年龄：");
	scanf("%d", &(contacts->age));
	printf("\n请输入联系人电话：");
	scanf("%s", contacts->tel);
	printf("\n请输入联系人地址：");
	scanf("%s", contacts->addr);
}

/*
* 函数名：Print_Contacts
* 用途：通讯录顺序表的打印联系人信息函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
*		pos 要打印pos下标的联系人信息
* 返回值：无
* 备注：只在本文件中可以调用
*/
static void Print_Contacts(AddressBook_SL *pAddressBook, int pos)
{
	assert(pAddressBook);
	char gender[11];
	//判断性别枚举的值
	switch (pAddressBook->a[pos].gender)
	{
		case 0:
		{
			strcpy(gender, "男");
			break;
		}
		case 1:
		{
			strcpy(gender, "女");
			break;
		}
		default:
		{
			strcpy(gender, "非二元性别");
			break;
		}
	}
	printf("%8s %15s %9d %18s     %s", pAddressBook->a[pos].name, gender, pAddressBook->a[pos].age, pAddressBook->a[pos].tel, pAddressBook->a[pos].addr);
	printf("\n");
}

/*
* 函数名：FindByName
* 用途：根据联系人姓名查找函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
*		name 要查找的姓名，char*类型的
* 返回值：返回-1表示没有找到，找到了返回对应的下标
* 备注：只在本文件中可以调用
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
* 函数名：AddressBook_Init
* 用途：通讯录顺序表的初始化函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
* 返回值：无
* 备注：无
*/
void AddressBook_Init(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	//调用顺序的初始化函数
	DSL_Init(pAddressBook);
}

/*
* 函数名：AddressBook_DesTroy
* 用途：通讯录顺序表的销毁函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
* 返回值：无
* 备注：无
*/
void AddressBook_DesTroy(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	//调用顺序表的销毁函数
	DSL_DesTroy(pAddressBook);
}

/*
* 函数名：AddressBook_AddContacts
* 用途：通讯录顺序表的添加联系人函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
* 返回值：无
* 备注：无
*/
void AddressBook_AddContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	//创建联系人结构体变量，并且赋值
	Contacts contacts;
	Input_Contacts(&contacts);
	//将联系人结构体变量插入到通讯录（顺序表）中
	DSL_PushBack(pAddressBook, contacts);
}

/*
* 函数名：AddressBook_DelContacts
* 用途：通讯录顺序表的删除指定联系人函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
* 返回值：无
* 备注：无
*/
void AddressBook_DelContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	char name[100];
	int num;
	printf("请输入要删除联系人的姓名：");
	scanf("%s", name);
	//在删除之前要先查找这个联系人是否存在
	num = FindByName(pAddressBook, name);
	if (num < 0)
	{
		printf("没有这个联系人，请检查是否输入有无！\n");
		return;
	}
	printf("\n");
	Print_Contacts(pAddressBook, num);
	char check;
	printf("\n请输入Y确认删除，输入非Y则取消：");
	getchar();
	scanf("%c", &check);
	if (check == 'Y' || check == 'y')
	{
		printf("删除成功！\n");
		DSL_Erase(pAddressBook, num);
	}
}

/*
* 函数名：AddressBook_ModifyContacts
* 用途：通讯录顺序表的修改指定联系人信息函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
* 返回值：无
* 备注：无
*/
void AddressBook_ModifyContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	//在修改之前要先查找这个联系人是否存在
	char name[100];
	int num;
	printf("请输入要修改联系人的姓名：");
	scanf("%s", name);
	//在删除之前要先查找这个联系人是否存在
	num = FindByName(pAddressBook, name);
	if (num < 0)
	{
		printf("没有这个联系人，请检查是否输入有无！\n");
		return;
	}
	printf("\n");
	Print_Contacts(pAddressBook, num);
	getchar();

	//创建联系人结构体变量，并且赋值
	Contacts contacts;
	Input_Contacts(&contacts);

	//修改原来的值
	DSL_Modify(pAddressBook, num, contacts);
}

/*
* 函数名：AddressBook_FindContacts
* 用途：通讯录顺序表的查找指定联系人函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
* 返回值：无
* 备注：无
*/
void AddressBook_FindContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	char name[100];
	int num;
	printf("请输入要查找联系人的姓名：");
	scanf("%s", name);
	num = FindByName(pAddressBook, name);
	if (num < 0)
	{
		printf("没有这个联系人，请检查是否输入有无！\n");
		return;
	}
	printf("\n");
	Print_Contacts(pAddressBook, num);
}

/*
* 函数名：AddressBook_ShowContacts
* 用途：通讯录顺序表的查看所有联系人函数
* 参数：pAddressBook 一个AddressBook_SL类型的指针，要操作的通讯录顺序表
* 返回值：无
* 备注：无
*/
void AddressBook_ShowContacts(AddressBook_SL *pAddressBook)
{
	assert(pAddressBook);
	printf("联系人姓名----联系人性别----联系人年龄----联系人电话------联系人地址\n");
	if (pAddressBook->length == 0)
	{
		return;
	}
	for (int i = 0; i < pAddressBook->length; i++)
	{
		Print_Contacts(pAddressBook, i);
	}
}