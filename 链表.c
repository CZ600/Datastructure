#include<stdio.h>
#include<malloc.h>

typedef struct Node  // typedef ���ڶ���һ���µĵĽṹ����
{
	int data;   // �����ڲ��Ĵ洢���ݵĲ���
	struct Node* next;  //������һ��ָ��node���͵�ָ��
} Node;

typedef struct BtNode
{
	int data;
	struct BtNode* lchild;
	struct BtNode* rchild;

}BtNode, * btnode;




int main()
{

	BtNode* bt;  // ����һ��BtNode���͵�ָ�����bt
	btnode p;  // Ҳ����ͨ�����ַ�ʽ������һ���ڵ�ָ�룬�ö��巽ʽ����һ�е��ǵ�Ч��
	bt = (BtNode*)malloc(sizeof(BtNode));  //Ϊbtָ�뿪���ڴ�ռ�

	int x = bt->data;
	int y = (*bt).data;  // ��������д���ǵȼ۵ģ���Ҫ��->�����ŵ�����



}