#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

/*
顺序栈的定义
*/
typedef struct 
{
	int data[MAXSIZE];  //存放栈中的数据
	int top; //定义栈顶
}SqStack;

/*
链栈的节点的定义
*/

typedef struct LNode
{
	int Data;  //数据域
	struct LNode *Next;  //指针域
}LNode;  //定义节点LNode

// 栈初始化
void Init_SeqStack(SqStack** s)
{
	// 开辟一块空间，并将该空间的地址赋给s
	*s = (SqStack*)malloc(sizeof(SqStack));
	(*s)->top = -1;
}

// 判栈为空
int Empty_SeqStack(SqStack* s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

// 入栈
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

// 出栈
void Pop_SeqStack(SqStack* s, int* x)
{
	if (s->top == -1)
		printf("栈为空!\n");
	else
	{
		*x = s->data[s->top];
		s->top--;
	}
}

// 取栈顶元素
void Top_SeqStack(SqStack* s, int* x)
{
	if (s->top == -1)
		printf("栈为空!\n");
	else
	{
		*x = s->data[s->top];
		printf("出栈成功！\n");
	}
}
// 输出
void Output_SeqStack(SqStack* s)
{
	SqStack *w;
	int i;
	printf("栈中的元素有：");
	for (i = s->top; i >= 0; i--)
		printf("%d ", s->data[i]);
	printf("\n");

}

int main()
{

}