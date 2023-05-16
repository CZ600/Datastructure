#include<stdio.h>
#define MaxSize 100

typedef struct  // 定义一个顺序表
{
	int data[MaxSize];
	int length;
};

int A[MaxSize];  // 这样就直接定义了一个长为MaxSize的顺序表， 效果同上
int n;

typedef struct ListNode  // 定义一个单链表，定义单链表的节点
{
	int Data; //存放数据
	struct List* node;  // 定义节点指针
}ListNode, * LNode;  

typedef struct DoubleNode  // 定义双链表的节点指针
{
	int Data;
	struct DoubleNode* prior;  //前驱
	struct DoubleNode* next;  // 后继
}DoubleNode;

int main()
{


}