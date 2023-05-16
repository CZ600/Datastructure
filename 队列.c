#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

/*
顺序队列的定义
*/
typedef struct
{
	int Data[MAXSIZE];
	int front;  // 队头指针
	int rear;  // 队尾指针
}SqQueue;  // 顺序队列的确立


/*
链队的定义
*/

typedef struct QNode  //队列节点的定义
{
	int data;
	struct QNode* Next;
}QNode;

typedef struct  // 链队列的定义
{
	QNode* front;  // 定义队头指针
	QNode* rear;  // 定义队尾指针
}LiQNode;  //定义链队列LiQNode

//初始化队列
int InitQueue(LiQNode* q)
{
	q->front = q->rear = (QNode*)malloc(sizeof(QNode));
	if (!q->front)
	{
		return -1;
	}
	q->front->Next = NULL;
	return 1;
}


//判断队列是否为空
int IsEmpty(LiQNode q)
{
	if (q.front == q.rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//入队列
int EnQueue(LiQNode* q, int a)
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (!p)
	{
		return -1;
	}
	p->data = a;
	p->Next = q->rear->Next;
	q->rear->Next = p;
	q->rear = p;
	return 1;

}
