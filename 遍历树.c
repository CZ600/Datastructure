#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode
{
	char data;
	struct BTNode* rchlid, * lchild;

}BTNode;


typedef struct QLNode
{
	BTNode data;
	struct QLNode* Next;

}QLNode;

typedef struct Queue
{
	QLNode* rear;
	QLNode* front;
	int length;
}Queue;

void initQueue(Queue* q)
{
	q->front = q->rear = (QLNode*)malloc(sizeof(QLNode));
	if (q->front->Next == NULL)
		return -1;
	q->front->Next = q->rear->Next = NULL;
	q->length = 0;
}

int isEmpty(Queue* q)
{
	if(q->front->Next == NULL)
	{
		return 1;

	}
	else
	{
		return 0;
	}
}

//���
void enQueue(Queue* q, BTNode x)
{
	QLNode* s;
	s = (QLNode*)malloc(sizeof(QLNode));
	s->data = x;
	s->Next = NULL;
	if (isEmpty(&q) == 1)
	{
		q->front = q->rear = s;
	}
	else
	{
		q->rear->Next = s;
		q->rear = s;
	}

}

//����
int deQueue(Queue* q, BTNode * t)
{
	QLNode* p;
	if (isEmpty(q))
	{
		return -1;
	}
	else if (isEmpty == 0)
	{
		p = q->front;
		if (q->front == q->rear)  //ֻ��һ��Ԫ��ʱ��������⴦��
		{
			*t = q->front->data;
			q->front = q->rear = NULL;
		}
		else
		{
			*t = q->front->data;
			q->front = q->front->Next;
		}
		free(p);
		return 1;
		
	}
}

char Vist(BTNode *p)
{
	if (p != NULL)
	{
		return p->data;
	}
	else
	{
		return -1;
	}
}

//���������ʽ ��-����-����
void preorder(BTNode *p)
{
	if (p != NULL)
	{
		Vist(&p);
		preorder(&p->lchild);
		preorder(&p->rchlid);
	}

}

//���������ʽ ��-����-����
void inorder(BTNode* p)
{
	if (p != NULL)
	{
		inorder(p->lchild);
		Vist(&p);
		inorder(p->rchlid);
	}
}

//������� ���Ҹ��ڵ�
void postorder(BTNode* p)
{
	if (p != NULL)
	{
		postorder(&p->lchild);
		postorder(&p->rchlid);
		Vist(p);
	}
}

// �������
void levelorder(BTNode* p)
{
	Queue q;
	while (p->lchild != NULL || p->rchlid != NULL)
	{
		enQueue(&q, *p);
		if (p->lchild != NULL)
		{
			levelorder(p->lchild);
		}
		if (p->rchlid != NULL)
		{
			levelorder(p->rchlid);
		}
		Vist(p);
	}
}

int main()
{

}