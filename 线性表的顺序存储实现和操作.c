#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef struct LNode* List;

/*
���ļ�������˳����������Ĵ����ͻ�������
�������ң����룬
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
	List PtrL;  // �����ṹ��
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;  // û��Ԫ�ؾ���-1
	return PtrL;  // ���ؽṹָ��
}
/*
�������Ա��е�Ԫ��
*/
 //int Find(ElementType X, List PtrL)
int find(int X, List PtrL)  //����
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X) //���β���
		i++;
	if (i > PtrL->Last) return -1;  //û�ҵ�����-1
	else
	{
		return i;  // �ҵ��˷��ش洢λ��
	}
}
/*
�������
��i��λ�ã��ϲ���һ��ֵΪX����Ԫ��
���ƶ����ٲ��룬�����һ����������ǰŲ��
*/
//

//void Insert(ElementType X, int i, List PtrL)
void Insert(int X, int i, List PtrL)
{
	int j;
	if (PtrL->Last == MAXSIZE - 1)  //����Ƿ���
	{
		printf_s("full");
		return;
	}
	if (i<1 || i>PtrL->Last + 2)  //���Ϸ���
	{
		printf_s("ilegality");
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--)  //��Ԫ�����ε�������ƶ�
	{
		PtrL->Data[j + 1] = PtrL->Data[j];  //�ƶ�
	}
	PtrL->Data[i - 1] = X;  //������Ԫ��
	PtrL->Last++;  // Last ��Ȼָ�����һ��Ԫ��
	return;

	
}

void DeleteElem(int i, List PtrL)
{
	int j;
	PtrL->Data[i - 1] = NULL;
	if (i<1 || i>PtrL->Last + 1) {  // �Ϸ����ж�
		printf_s("�����ڵ�%d��Ԫ��", i);
		return;
	}
	for (j = i - 1; j < PtrL->Last; j++)  // ���Ų��Ԫ��
	{
		PtrL->Data[j - 1] = PtrL->Data[j];
	}
	PtrL->Last--;  // Last��Ȼָ�����һ��Ԫ��
}