#include<stdio.h>
#include<malloc.h>

typedef struct Node  // typedef 用于定义一个新的的结构类型
{
	int data;   // 链表内部的存储数据的部分
	struct Node* next;  //定义了一个指向node类型的指针
} Node;

typedef struct BtNode
{
	int data;
	struct BtNode* lchild;
	struct BtNode* rchild;

}BtNode, * btnode;




int main()
{

	BtNode* bt;  // 定义一个BtNode类型的指针变量bt
	btnode p;  // 也可以通过这种方式来定义一个节点指针，该定义方式与上一行的是等效的
	bt = (BtNode*)malloc(sizeof(BtNode));  //为bt指针开辟内存空间

	int x = bt->data;
	int y = (*bt).data;  // 以上两种写法是等价的，主要“->”符号的意义



}