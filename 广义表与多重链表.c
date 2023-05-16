#include<stdio.h>

/*
广义表示线性表的推广
对于线性而言，n个元素都是基本的单个元素
对于广义表，这些元素不仅仅可以是单元素，也可以是另一广义表
*/

typedef struct GNode* GList;
struct GNode
{
	int Tag;  //标志域，区分不同类型，0表示结点是单元素，1表示节点是广义表
	union {  //子表指针域Sublist与单元素数据域Data复用， 也就是共享存储空间
		int Data;  //elemental type 
		GList SubList;
	}URegion;
	GList Next;  //指向后继结点
};


/*
多重链表：链表中的节点可能同时隶属于多个链
多重链表中的结点的指针域会有多个，如前面的例子中包含的Next和SubList两个指针域
但是包含两个指针域的链表不一定是多重链表，比如双向链表不是多重链表
多重链表用途广泛，
基本上树、图这样相对复杂的数据结构都可以采用多重链表的方式进行存储

采用十字链表的方式来存储
*/


int main()
{
	int i = 1;
}