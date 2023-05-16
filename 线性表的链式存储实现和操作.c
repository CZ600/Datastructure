#include<stdio.h>

typedef struct LNode* List;

/*
struct LNode
{
	ElementType Data;
	List Next;
};

struct Lnode L;
List PtrL;

*/
struct LNode
{
	int Data; 
	List Next;
};

struct LNode L;  //
List PtrL;  // 定义一个指向List类型数据的的指针

/*
求表长,链表遍历的方式来求表长
*/
int Length(List PtrL)
{
	List p = PtrL;
	int j = 0;
	while (p) {
		p = p->Next;
		j++;
	}
	return j;

}

/*
查找操作， 也是采用链表遍历的方式
*/
//按照序号查找
List FindKth(int K, List PtrL)
{
	List p = PtrL;
	int i = 1;
	while (p != NULL && i < K) {
		p = p->Next;
		i++;
	}
	if (i == K) return p;
	else return NULL;
}
//按照内容查找
List FindXth(int X, List PtrL)
{
	List p = PtrL;  //头指针
	while (p != NULL && p->Data != X) {  //循环查找直到找到需要的值
		p = p->Next;
	}
	return p;
}

/*
删除操作
*/

List Delete(int i, List PtrL)
{
	List p, s;
	if (i == 1)
	{
		s = PtrL;  //s指向第一个节点
		if (PtrL != NULL) PtrL = PtrL->Next;// 从链表中删除（断开连接）
		else return NULL;
		free(s);//释放被删除的节点
		return PtrL;   
	}

	p = FindKth(i-1, PtrL);  //p为第i-1个节点
	if (p == NULL) {  //排除错误情况
		printf_s("第%d个节点不存在", i);
	}
	else if(p->Next == NULL){
		printf_s("第%d个节点不存在", i);
	}
	else
	{
		s = p->Next;  //s指向第i个节点
		p->Next = s->Next;  //将第i个节点从链表中删除
		free(s);  //释放空间
		return PtrL;  //返回链表
	}
}






int main()
{

}