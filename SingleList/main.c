#include "SingleList.h"

int main()
{
	SingleListNode *SL_Node = NULL;

	SingleList_PushBack(&SL_Node, 25);//����Ҫ���ݽڵ��ַ�ĵ�ַ����Ϊ������ݵ��ǽڵ�ĵ�ַ��ֻ�ǰ����ָ��������ݹ�ȥ��ʵ�����Ǵ�ֵ���ã��������������������ڵ��ַ�Ŀ����������Ǻ�������Ҫ�޸������ַ��ֵ������Ҫ��������ڵ��ַָ��ĵ�ַ�ſ����޸�����ڵ�ָ�������ֵ��
	SingleList_PushBack(&SL_Node, 26);
	SingleList_PushBack(&SL_Node, 27);
	SingleList_PushBack(&SL_Node, 28);
	SingleList_PushFront(&SL_Node, 24);

	SingleList_PopBack(&SL_Node);
	SingleList_PopFront(&SL_Node);
	SingleList_Print(SL_Node, SLPrintInt);//ע������ڵ����Ѿ���ָ���˲���Ҫ�ٴ�ȡ��ַ�ˡ�
	return 0;
}