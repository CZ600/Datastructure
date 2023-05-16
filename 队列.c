#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

/*
˳����еĶ���
*/
typedef struct
{
	int Data[MAXSIZE];
	int front;  // ��ͷָ��
	int rear;  // ��βָ��
}SqQueue;  // ˳����е�ȷ��


/*
���ӵĶ���
*/

typedef struct QNode  //���нڵ�Ķ���
{
	int data;
	struct QNode* Next;
}QNode;

typedef struct  // �����еĶ���
{
	QNode* front;  // �����ͷָ��
	QNode* rear;  // �����βָ��
}LiQNode;  //����������LiQNode

//��ʼ������
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


//�ж϶����Ƿ�Ϊ��
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

//�����
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
