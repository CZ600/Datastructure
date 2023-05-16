#include<stdio.h>

/*
采用一种典型的多重链表————十字链表来存储稀疏矩阵
只存储矩阵非零项
节点的数据域包括：Row， Col， Value
每个节点通过两个指针域来白同行同列串联起来
行指针：Right
列指针：Down
*/

typedef struct LNode* Ln;

struct LNode {
	int Data;
	Ln Right; 
	Ln Down;
}list;

struct 
{
	int Data;
	Ln Right;
};







int main()
{

}