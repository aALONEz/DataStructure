#include "Snake.h"

void Test(void)
{
	//����̰����
	Snake snake = {0};//�ֲ���������Ҫ��ʼ����ֵ
	GameStart(&snake);
	GameRun(&snake);
	GameEnd(&snake);
}

int main()
{
	setlocale(LC_ALL, "");//C�����ַ����ػ�
	Test();
	return 0;
}
