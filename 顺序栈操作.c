

//设立一个顺序栈

#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
	int data[MAXSIZE];  // 存储空间
	int *top;  // 设立栈顶
}SqStack;  // 建立一个名字为SqStack的顺序栈


// 初始化一个顺序栈


void Stack(SqStack &st)
{
	*st.top = -1;  // 建立空的栈
}




int main()
{

}


/*
#include<stdio.h>
#define MAXSIZE 10
typedef struct {
	int data[MAXSIZE];//空间--静态分配
	int top;//栈顶
}Stack;



void initStack(Stack& s)
{
	s.top = 0;//栈为空
}
*/
