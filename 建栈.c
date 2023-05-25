#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

/*
˳��ջ�Ķ���
*/
typedef struct 
{
	int data[MAXSIZE];  //���ջ�е�����
	int top; //����ջ��
}SqStack;

/*
��ջ�Ľڵ�Ķ���
*/

typedef struct LNode
{
	int Data;  //������
	struct LNode *Next;  //ָ����
}LNode;  //����ڵ�LNode

// ջ��ʼ��
void Init_SeqStack(SqStack** s)
{
	// ����һ��ռ䣬�����ÿռ�ĵ�ַ����s
	*s = (SqStack*)malloc(sizeof(SqStack));
	(*s)->top = -1;
}

// ��ջΪ��
int Empty_SeqStack(SqStack* s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

// ��ջ
void Push_Stack(SqStack* s, int x)
{
	if (s->top == MAXSIZE - 1)
		printf("Stack is full!\n");
	else
	{
		s->top++;
		s->data[s->top] = x;
	}

}

// ��ջ
void Pop_SeqStack(SqStack* s, int* x)
{
	if (s->top == -1)
		printf("ջΪ��!\n");
	else
	{
		*x = s->data[s->top];
		s->top--;
	}
}

// ȡջ��Ԫ��
void Top_SeqStack(SqStack* s, int* x)
{
	if (s->top == -1)
		printf("ջΪ��!\n");
	else
	{
		*x = s->data[s->top];
		printf("��ջ�ɹ���\n");
	}
}
// ���
void Output_SeqStack(SqStack* s)
{
	SqStack *w;
	int i;
	printf("ջ�е�Ԫ���У�");
	for (i = s->top; i >= 0; i--)
		printf("%d ", s->data[i]);
	printf("\n");

}

int main()
{

}