#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 15
//����ջ
typedef struct SqStack
{
	char Data[MAXSIZE];
	int top;
}SqStack;  // ˳��ջ���Ͷ���

//��ʼ��ջ
void InitStack(SqStack *sq)
{
	sq->top = -1;
	
}

//�ж�ջ�Ƿ�Ϊ��
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

//��ջ
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

//��ջ
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

//�ж��ַ����ȼ�
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

//����ִ��ת�������ĺ���
char transform(char list[], SqStack *num,SqStack *sign)
{
	int i = 0;
	char x;
	for (i = 0; i <= strlen(list); i++)
	{
		if (list[i]=='('|| list[i] == ')')  // �ж��Ƿ�Ϊ����
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
		else if (list[i]<=122&&list[i]>=97)  //�ж��Ƿ�Ϊ��ĸ
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