#pragma once
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>

//游戏区域，而非整个控制台界面
#define GAME_MAP_MAX_COLS 56
#define GAME_MAP_MAX_LINES 25

//墙体
#define WALL L'□'

//蛇身
#define SNAKE_BODY L'○'

//蛇头
#define SNAKE_HEAD L'●'

//食物
#define FOOD L'●'

//蛇头默认起始坐标
#define SNAKE_POS_X 22
#define SNAKE_POS_Y 5

//默认蛇长
#define SNAKE_LENGTH 5

//检测按键是否按下
#define KEY_PRESS(VK) ((GetAsyncKeyState(VK) & 0X1) ? 1 : 0)


//蛇身节点
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

//游戏状态
typedef enum GameStatus
{
	Game_Ok,
	Game_Esc,
	Kill_By_Wall,
	Kill_By_Self
}GameStatus;

//蛇的方向
typedef enum SnakeDirection
{
	Snake_Up,
	Snake_Down,
	Snake_Left,
	Snake_Right
}SnakeDirection;

//贪吃蛇
typedef struct Snake
{
	pSnakeNode pSnakeHead;//整条蛇的指针，指向蛇头节点
	pSnakeNode pFood;//食物的指针
	int Score;//当前分数
	int FoodWeight;//食物分数
	int SnakeSpeed;//蛇的速度，速度越快，调用sleep的时间越短
	GameStatus Status;//游戏状态
	SnakeDirection SDirection;//蛇方向
}Snake;

void GameStart(Snake* snake);
void CreateMap(void);
void InitSnake(Snake* pSnake);
void PrintSnake(Snake* pSnake);
void CreateFood(Snake* pSnake);
void GameRun(Snake* pSnake);
void SnakeMove(Snake* pSnake);
void GameEnd(Snake* pSnake);
