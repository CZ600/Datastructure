#include<stdio.h>
#define MaxSize 100

typedef struct  // ����һ��˳���
{
	int data[MaxSize];
	int length;
};

int A[MaxSize];  // ������ֱ�Ӷ�����һ����ΪMaxSize��˳��� Ч��ͬ��
int n;

typedef struct ListNode  // ����һ�����������嵥����Ľڵ�
{
	int Data; //�������
	struct List* node;  // ����ڵ�ָ��
}ListNode, * LNode;  

typedef struct DoubleNode  // ����˫����Ľڵ�ָ��
{
	int Data;
	struct DoubleNode* prior;  //ǰ��
	struct DoubleNode* next;  // ���
}DoubleNode;

int main()
{


}