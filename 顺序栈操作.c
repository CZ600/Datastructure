

//����һ��˳��ջ

#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
	int data[MAXSIZE];  // �洢�ռ�
	int *top;  // ����ջ��
}SqStack;  // ����һ������ΪSqStack��˳��ջ


// ��ʼ��һ��˳��ջ


void Stack(SqStack &st)
{
	*st.top = -1;  // �����յ�ջ
}




int main()
{

}


/*
#include<stdio.h>
#define MAXSIZE 10
typedef struct {
	int data[MAXSIZE];//�ռ�--��̬����
	int top;//ջ��
}Stack;



void initStack(Stack& s)
{
	s.top = 0;//ջΪ��
}
*/
