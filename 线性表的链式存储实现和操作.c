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
List PtrL;  // ����һ��ָ��List�������ݵĵ�ָ��

/*
���,��������ķ�ʽ�����
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
���Ҳ����� Ҳ�ǲ�����������ķ�ʽ
*/
//������Ų���
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
//�������ݲ���
List FindXth(int X, List PtrL)
{
	List p = PtrL;  //ͷָ��
	while (p != NULL && p->Data != X) {  //ѭ������ֱ���ҵ���Ҫ��ֵ
		p = p->Next;
	}
	return p;
}

/*
ɾ������
*/

List Delete(int i, List PtrL)
{
	List p, s;
	if (i == 1)
	{
		s = PtrL;  //sָ���һ���ڵ�
		if (PtrL != NULL) PtrL = PtrL->Next;// ��������ɾ�����Ͽ����ӣ�
		else return NULL;
		free(s);//�ͷű�ɾ���Ľڵ�
		return PtrL;   
	}

	p = FindKth(i-1, PtrL);  //pΪ��i-1���ڵ�
	if (p == NULL) {  //�ų��������
		printf_s("��%d���ڵ㲻����", i);
	}
	else if(p->Next == NULL){
		printf_s("��%d���ڵ㲻����", i);
	}
	else
	{
		s = p->Next;  //sָ���i���ڵ�
		p->Next = s->Next;  //����i���ڵ��������ɾ��
		free(s);  //�ͷſռ�
		return PtrL;  //��������
	}
}






int main()
{

}