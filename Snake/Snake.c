#include "Snake.h"

/// <summary>
/// 将光标移动到指定位置
/// </summary>
/// <param name="x">指定位置的x坐标</param>
/// <param name="y">指定位置的y坐标</param>
static void Cursor_SetPos(int x, int y)
{
	HANDLE conHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x , y };
	SetConsoleCursorPosition(conHandle, pos);
}

/// <summary>
/// 贪吃蛇游戏欢迎函数，主要打印一些欢迎信息！
/// </summary>
/// <param name="">无参数</param>
static void WelcomeToGame(void)
{
	//欢迎信息
	Cursor_SetPos(40, 15);
	printf("欢迎游玩贪吃蛇！！\n");
	Cursor_SetPos(40, 25);
	system("pause");//控制台会暂停，控制台会输出请按任意键继续。
	system("cls");//清屏
	
	//操作指南
	Cursor_SetPos(6, 15);
	printf("请使用小键盘的↑、↓、←、→来控制蛇的移动，空格切换速度（速度包括普通（默认）和快速）。\n");
	Cursor_SetPos(40, 16);
	printf("感谢游玩！\n");
	Cursor_SetPos(40, 28);
	system("pause");//控制台会暂停，控制台会输出请按任意键继续。
	system("cls");//清屏
}

/// <summary>
/// 贪吃蛇游戏绘制地图函数
/// </summary>
/// <param name="">无参数</param>
void CreateMap(void)
{
	//上
	Cursor_SetPos(0, 0);
	for (int i = 0; i <= GAME_MAP_MAX_COLS; i += 2)
	{
		wprintf(L"%lc", WALL);
	}

	//下
	Cursor_SetPos(0, 25);
	for (int i = 0; i <= GAME_MAP_MAX_COLS; i += 2)
	{
		wprintf(L"%lc", WALL);
	}

	//左
	for (int i = 0; i < GAME_MAP_MAX_LINES; i++)
	{
		Cursor_SetPos(GAME_MAP_MAX_LINES - GAME_MAP_MAX_LINES, i + 1);
		wprintf(L"%lc", WALL);
	}
	
	//右
	for (int i = 0; i < GAME_MAP_MAX_LINES; i++)
	{
		Cursor_SetPos(GAME_MAP_MAX_COLS, i + 1);
		wprintf(L"%lc", WALL);
	}
}

/// <summary>
/// 贪吃蛇游戏打印蛇函数
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体</param>
void PrintSnake(Snake* pSnake)
{
	SnakeNode* tmpSnakeNode = pSnake->pSnakeHead;
	int i = 0;
	do
	{
		Cursor_SetPos(tmpSnakeNode->x, tmpSnakeNode->y);
		if (i == 0)//打印蛇头
		{
			wprintf(L"%lc", SNAKE_HEAD);
			i++;
		}
		else//打印蛇身
		{
			wprintf(L"%lc", SNAKE_BODY);
		}
		tmpSnakeNode = tmpSnakeNode->next;
	} while (tmpSnakeNode && i);
}

/// <summary>
/// 初始化贪吃蛇游戏中蛇的默认信息。
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体</param>
void InitSnake(Snake* pSnake)
{
	//创建5个蛇身节点
	pSnakeNode curr = NULL;
	for (int i = 0; i < SNAKE_LENGTH; i++)
	{
		curr = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (curr == NULL)
		{
			perror("InitSnake():malloc()");
			exit(1);
		}
		curr->x = SNAKE_POS_X + (SNAKE_LENGTH * 2) - (i * 2);
		curr->y = SNAKE_POS_Y;
		curr->next = NULL;

		if (pSnake->pSnakeHead == NULL)//如果当前没有蛇身节点就直接让当前节点等于蛇身节点
		{
			pSnake->pSnakeHead = curr;
		}
		else
		{
			curr->next = pSnake->pSnakeHead;
			pSnake->pSnakeHead = curr;
		}
	}

	//初始化蛇信息
	pSnake->SDirection = Snake_Left;//蛇默认方向
	pSnake->SnakeSpeed = 1;//蛇默认速度
	pSnake->pFood = NULL;//默认食物指针
	pSnake->FoodWeight = 10;//食物默认分数
	pSnake->Status = Game_Ok;

	//打印蛇身
	PrintSnake(pSnake);
}

/// <summary>
/// 绘制贪吃蛇游戏中的食物。
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体</param>
void CreateFood(Snake* pSnake)
{
	pSnakeNode currFood = NULL;

	currFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (currFood == NULL)
	{
		perror("CreateFood():malloc()\n");
		exit(1);
	}
	//随机食物位置
again:
	do
	{
		currFood->x = rand() % (GAME_MAP_MAX_COLS - 3) + 2;
		currFood->y = rand() % (GAME_MAP_MAX_LINES - 1) + 1;
	} while ((currFood->x % 2) != 0);
	pSnakeNode currSnakeHead = pSnake->pSnakeHead;
	while (currSnakeHead)//食物位置不可以和蛇身重叠
	{
		if ((currFood->x == currSnakeHead->x) && (currFood->y == currSnakeHead->y))
		{
			goto again;
		}
		currSnakeHead = currSnakeHead->next;
	}
	currFood->next = NULL;
	pSnake->pFood = currFood;
	//打印食物
	Cursor_SetPos(currFood->x, currFood->y);
	wprintf(L"%lc", FOOD);
}

/// <summary>
/// 贪吃蛇游戏打印帮助信息函数
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体</param>
static void PrintHelpInfo(Snake* pSnake)
{
	Cursor_SetPos(GAME_MAP_MAX_COLS + 5, 5);
	printf("↑：向上移动");
	Cursor_SetPos(GAME_MAP_MAX_COLS + 5, 7);
	printf("↓：向下移动");
	Cursor_SetPos(GAME_MAP_MAX_COLS + 5, 9);
	printf("←：向左移动");
	Cursor_SetPos(GAME_MAP_MAX_COLS + 5, 11);
	printf("→：向右移动");
}

/// <summary>
/// 游戏正式开始游玩前的准备游戏函数
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体</param>
void GameStart(Snake* pSnake)
{
	//设置游戏画面（控制台信息）
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	srand((unsigned int)time(NULL));//设置随机数种子

	//隐藏光标
	HANDLE conHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前控制台句柄，只有拿到句柄才可以操作对应的窗口
	CONSOLE_CURSOR_INFO CursorInfo;//控制台光标结构体
	GetConsoleCursorInfo(conHandle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false;//不显示光标
	SetConsoleCursorInfo(conHandle, &CursorInfo);

	//打印欢迎信息
	WelcomeToGame();

	//绘制地图
	CreateMap();

	//初始化蛇
	InitSnake(pSnake);

	//绘制食物
	CreateFood(pSnake);

	//打印帮助信息
	PrintHelpInfo(pSnake);
}

/// <summary>
/// 贪吃蛇游戏打印得分函数
/// </summary>
/// <param name="pSnake"></param>
static void PrintScore(Snake* pSnake)
{
	Cursor_SetPos(GAME_MAP_MAX_COLS + 5, 20);
	printf("得分：%d    食物分值：%d", pSnake->Score, pSnake->FoodWeight);
	Cursor_SetPos(GAME_MAP_MAX_COLS + 5, 15);
	printf("Space：切换速度    当前速度：%s", (pSnake->SnakeSpeed == 1) ? "慢" : "快");
}

/// <summary>
/// 贪吃蛇游戏检测部分按键按下函数
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体指针</param>
static void CheckKey(Snake* pSnake)
{
	//检测按键之前每次都先更新一下分数
	PrintScore(pSnake);

	//检测按键,↑、↓、←、→、Space、ESC
	if ((KEY_PRESS(VK_UP)) && (pSnake->SDirection != Snake_Down))//上方向键检测
	{
		pSnake->SDirection = Snake_Up;
	}
	else if((KEY_PRESS(VK_DOWN)) && (pSnake->SDirection != Snake_Up))//下方向键检测
	{
		pSnake->SDirection = Snake_Down;
	}
	else if ((KEY_PRESS(VK_LEFT)) && (pSnake->SDirection != Snake_Right))//左方向键检测
	{
		pSnake->SDirection = Snake_Left;
	}
	else if ((KEY_PRESS(VK_RIGHT)) && (pSnake->SDirection != Snake_Left))//右方向键检测
	{
		pSnake->SDirection = Snake_Right;
	}
	else if (KEY_PRESS(VK_SPACE))//空格按键检测
	{
		pSnake->SnakeSpeed = (pSnake->SnakeSpeed == 1) ? 2 : 1;
	}
	else if (KEY_PRESS(VK_ESCAPE))//退出按键检测
	{
		pSnake->Status = Game_Esc;
		return;
	}
}

/// <summary>
/// 检测某个坐标上是否有食物
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体指针</param>
/// <param name="pos_x">坐标x</param>
/// <param name="pos_y">坐标y</param>
/// <returns></returns>
static bool CheckFood(Snake* pSnake, int pos_x, int pos_y)
{
	if ((pSnake->pFood->x == pos_x) && (pSnake->pFood->y == pos_y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// 贪吃蛇游戏蛇移动函数
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体指针</param>
void SnakeMove(Snake* pSnake)
{
	//创建一个临时节点用来保存蛇头下一个要去的位置
	SnakeNode* tmpSnakeNode = (SnakeNode*)malloc(sizeof(SnakeNode));
	tmpSnakeNode->next = NULL;

	switch (pSnake->SDirection)
	{
		case Snake_Up:
		{
			//向上移动X轴不变Y轴减1
			tmpSnakeNode->x = pSnake->pSnakeHead->x;
			tmpSnakeNode->y = pSnake->pSnakeHead->y - 1;
			break;
		}
		case Snake_Down:
		{
			//向下移动X轴不变Y轴加1
			tmpSnakeNode->x = pSnake->pSnakeHead->x;
			tmpSnakeNode->y = pSnake->pSnakeHead->y + 1;
			break;
		}
		case Snake_Left:
		{
			//向左移动Y轴不变X轴减2
			tmpSnakeNode->x = pSnake->pSnakeHead->x - 2;
			tmpSnakeNode->y = pSnake->pSnakeHead->y;
			break;
		}
		case Snake_Right:
		{
			//向右移动Y轴不变X轴加2
			tmpSnakeNode->x = pSnake->pSnakeHead->x + 2;
			tmpSnakeNode->y = pSnake->pSnakeHead->y;
			break;
		}
	}
	//检查是否吃到食物
	SnakeNode* tmpSnakeBodyNode = pSnake->pSnakeHead;
	//头插到链表
	tmpSnakeNode->next = tmpSnakeBodyNode;
	pSnake->pSnakeHead = tmpSnakeNode;
	if (CheckFood(pSnake, tmpSnakeNode->x, tmpSnakeNode->y))
	{
		//增加得分
		pSnake->Score += pSnake->FoodWeight;

		//打印蛇身
		PrintSnake(pSnake);

		//释放原食物节点
		free(pSnake->pFood);
		pSnake->pFood = NULL;

		//重新生成食物
		CreateFood(pSnake);
	}
	else
	{
		//释放尾节点
		while (tmpSnakeNode->next->next)
		{
			tmpSnakeNode = tmpSnakeNode->next;
		}
		SnakeNode* currSnakeNode = tmpSnakeNode;
		tmpSnakeNode = tmpSnakeNode->next;
		currSnakeNode->next = NULL;
		int x, y;
		x = tmpSnakeNode->x;//保留尾节点坐标
		y = tmpSnakeNode->y;
		free(tmpSnakeNode);
		tmpSnakeNode = NULL;

		//打印蛇身
		PrintSnake(pSnake);

		//将尾节点的位置打印成空白字符
		Cursor_SetPos(x, y);
		printf("  ");
	}
}

/// <summary>
/// 贪吃蛇游戏检测是否撞到墙函数
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体指针</param>
static void KillByWall(Snake* pSnake)
{
	if ((pSnake->pSnakeHead->x == 0) || (pSnake->pSnakeHead->x == (GAME_MAP_MAX_COLS - 2)) || (pSnake->pSnakeHead->y == 0) || (pSnake->pSnakeHead->y == GAME_MAP_MAX_LINES))
	{
		pSnake->Status = Kill_By_Wall;
	}
}

/// <summary>
/// 贪吃蛇游戏检测是否撞到自己函数
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体指针</param>
static void KillBySelf(Snake* pSnake)
{
	SnakeNode* tmpSnakeNode = pSnake->pSnakeHead->next->next;

	while (tmpSnakeNode)
	{
		if ((tmpSnakeNode->x == pSnake->pSnakeHead->x) && (tmpSnakeNode->y == pSnake->pSnakeHead->y))
		{
			pSnake->Status = Kill_By_Self;
			return;
		}
		tmpSnakeNode = tmpSnakeNode->next;

	}
}

/// <summary>
/// 贪吃蛇游戏游玩运行中的函数
/// </summary>
/// <param name="pSnake">贪吃蛇游戏的指针，Snake类型的结构体指针</param>
void GameRun(Snake* pSnake)
{
	do
	{
		//检测按键
		CheckKey(pSnake);

		//蛇移动
		SnakeMove(pSnake);

		//检测撞墙
		KillByWall(pSnake);

		//检测撞自己
		KillBySelf(pSnake);

		//控制台睡眠
		if (pSnake->SnakeSpeed == 1)
		{
			Sleep(280);
		}
		else
		{
			Sleep(100);
		}
	} while (pSnake->Status == Game_Ok);
}

void GameEnd(Snake* pSnake)
{
	system("cls");//清屏
	Cursor_SetPos(35, 12);
	switch (pSnake->Status)
	{
		case Game_Esc:
		{
			printf("游戏退出中....");
			break;
		}
		case Kill_By_Wall:
		{
			printf("很遗憾，撞墙了！游戏退出中....");
			break;
		}
		case Kill_By_Self:
		{
			printf("很遗憾，咬到自己了！游戏退出中....");
			break;
		}
	}
	Sleep(1000);
	//释放链表
	SnakeNode* tmpSnakeNode = pSnake->pSnakeHead;
	SnakeNode* delSnakeNode = NULL;
	while (tmpSnakeNode)
	{
		delSnakeNode = tmpSnakeNode;
		tmpSnakeNode = tmpSnakeNode->next;
		free(delSnakeNode);
	}
	pSnake->pSnakeHead = NULL;

	free(pSnake->pFood);
	pSnake->pFood = NULL;
	pSnake->FoodWeight = 0;
	pSnake->Score = 0;
	pSnake->SDirection = Snake_Left;
	pSnake->SnakeSpeed = 1;

	system("cls");//清屏
	Cursor_SetPos(39, 12);
	printf("游戏资源释放完成");
	Cursor_SetPos(39, 15);
	system("pause");//控制台会暂停，控制台会输出请按任意键继续。
}