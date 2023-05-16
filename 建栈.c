#include<stdio.h>
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



int main()
{

}