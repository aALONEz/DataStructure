#include "Snake.h"

void Test(void)
{
	//创建贪吃蛇
	Snake snake = {0};//局部变量定义要初始化赋值
	GameStart(&snake);
	GameRun(&snake);
	GameEnd(&snake);
}

int main()
{
	setlocale(LC_ALL, "");//C语言字符本地化
	Test();
	return 0;
}
