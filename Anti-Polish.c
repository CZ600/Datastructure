#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 15
//定义栈
typedef struct SqStack
{
	char Data[MAXSIZE];
	int top;
}SqStack;  // 顺序栈类型定义

//初始化栈
void InitStack(SqStack *sq)
{
	sq->top = -1;
	
}

//判断栈是否为空
bool empty(SqStack s)
{
	if (s.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//入栈
void Push(SqStack *sq, char x)
{
	if (sq->top==MAXSIZE-1)
	{
		printf_s("full!");
		return 0;
	}
	else
	{
		++(sq->top);
		sq->Data[sq->top] = x;
		return 1;
	}
}

//出栈
void Pop(SqStack* sq, char *x)
{
	if (sq->top == -1)
	{
		printf_s("empty");
		return 0;
	}
	else
	{
		*x = sq->Data[sq->top];
		--(sq->top);
		return 1;
	}
}

//判断字符优先级
int IsSign(char s)
{
	switch (s)
	{
		case '^':
			return 5;
			break;
		case '*':
			return 4;
			break;
		case '/':
			return 4;
			break;
		case '%':
			return 4;
			break;
		case '+':
			return 3;
			break;
		case '-':
			return 3;
			break;
		case '(':
			return 2;
			break;
		case '$':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}

//具体执行转化操作的函数
char transform(char list[], SqStack *num,SqStack *sign)
{
	int i = 0;
	char x;
	for (i = 0; i <= strlen(list); i++)
	{
		if (list[i]=='('|| list[i] == ')')  // 判断是否为括号
		{
			if (list[i]=='(')
			{
				Push(sign, list[i]);
				continue;
			}
			else if (list[i]==')')
			{
				if (sign->top == '(')
				{
					Pop(sign, &x);
					continue;
				}
				else 
				{
					Pop(sign, &x);
					Push(num, x);
					continue;
				}
			}
			
		}
		else if (list[i]<=122&&list[i]>=97)  //判断是否为字母
		{
			Push(num, list[i]);
		}
		else if ( IsSign(list[i])>=1 && IsSign(list[i])<=5 )
		{
			
			if (empty(*sign) == true || sign->Data[sign->top]=='(')
			{
				Push(sign, list[i]);
				continue;
			}
			else if (IsSign(list[i]) > IsSign(sign->Data[sign->top]))
			{
				Push(sign, list[i]);
				continue;
			}
			else if (IsSign(list[i]) <= IsSign(sign->Data[sign->top]))
			{
				Pop(sign, &x);
				Push(num, x);
				continue;
			}
		}
	}
}

void main()
{
	char nifix_expression[] = { '(', 'a', 'b', '*', 'c', ')', '^', 'd', '^',
		'(', 'e', '*', 'f', '/', 'g', ')', '-', 'h', '*', 'i', '\0' };
	int i = 0;
	SqStack num;
	SqStack sign;
	InitStack(&num);
	InitStack(&sign);
	transform(nifix_expression, &num, &sign);
	for (i = 0; i < strlen(num.Data); i++)
	{
		printf_s("%c", num.Data[i]);
	}
}