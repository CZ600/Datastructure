#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct LNode* List;

/*
本文件涵盖了顺序表（单链表）的创建和基本操作
包括查找，插入，
*/



/*

struct LNode {
	ElementType Data[MAXSIZE];
	int Last;
};
struct LNode L;

List PtrL;

*/

struct LNode {
	int Data[MAXSIZE];
	int Last;
};
struct LNode L;

List PtrL;

List MakeEmpty()
{
	List PtrL;  // 建立结构体
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;  // 没有元素就是-1
	return PtrL;  // 返回结构指针
}
/*
查找线性表中的元素
*/
 //int Find(ElementType X, List PtrL)
int find(int X, List PtrL)  //查找
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X) //依次查找
		i++;
	if (i > PtrL->Last) return -1;  //没找到返回-1
	else
	{
		return i;  // 找到了返回存储位置
	}
}
/*
插入操作
第i个位置，上插入一个值为X的新元素
先移动，再插入，从最后一个，依次向前挪动
*/
//

//void Insert(ElementType X, int i, List PtrL)
void Insert(int X, int i, List PtrL)
{
	int j;
	if (PtrL->Last == MAXSIZE - 1)  //检查是否满
	{
		printf_s("full");
		return;
	}
	if (i<1 || i>PtrL->Last + 2)  //检查合法性
	{
		printf_s("ilegality");
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--)  //将元素依次倒序向后移动
	{
		PtrL->Data[j + 1] = PtrL->Data[j];  //移动
	}
	PtrL->Data[i - 1] = X;  //插入新元素
	PtrL->Last++;  // Last 仍然指向最后一个元素
	return;

	
}

void DeleteElem(int i, List PtrL)
{
	int j;
	PtrL->Data[i - 1] = NULL;
	if (i<1 || i>PtrL->Last + 1) {  // 合法性判断
		printf_s("不存在第%d个元素", i);
		return;
	}
	for (j = i - 1; j < PtrL->Last; j++)  // 向后挪动元素
	{
		PtrL->Data[j - 1] = PtrL->Data[j];
	}
	PtrL->Last--;  // Last仍然指向最后一个元素
}