#include "Queue.h"

int main()
{
	Queue q;

	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	printf("%d\n", QueueFront(&q));	//1
	printf("%d\n", QueueBack(&q));	//2
	printf("%d\n", QueueSize(&q));	//2
	printf("%d\n", QueueFront(&q));	//1
	printf("%d\n", QueueBack(&q));	//2
	QueuePop(&q);
	printf("%d\n", QueueSize(&q));	//1
	printf("%d\n", QueueFront(&q));	//2
	printf("%d\n", QueueEmpty(&q));	//0
	printf("%d\n", QueueSize(&q));	//1
	QueueDestroy(&q);
	printf("%d\n", QueueSize(&q));	//0
	printf("%d\n", QueueEmpty(&q));	//1
	printf("%d\n", QueueSize(&q));	//0
	return 0;
}
