#include<stdio.h>
#define MAXSIZE 255
typedef struct node
{
	int i, j;  //�����±�
	int e; 
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];  // ����Ԫ����Ԫ�����
	int mu, nu, tu;  // ���������(mu)������(nu)���ͷ���Ԫ(tu)�ĸ���
}RLSMatrix;

RLSMatrix T, M;

void TransposeSMatrix(RLSMatrix M, RLSMatrix *T) {
	T->mu = M.nu;                           //T��������ԭ��������
	T->nu = M.mu;                           //T��������ԭ��������
	T->tu = M.tu;                           //����Ԫ�ظ�����ͬ
	if (!T->tu)  return;

	int q = 1;                 //ת�þ�������Ԫ���±�
	for (int col = 1; col <= M.nu; ++col) {  //ö��ÿһ��
		for (int p = 1; p <= M.tu; ++p) {    //����M�д��ڸ��еķ���Ԫ
			if (M.data[p].j == col) {
				T->data[q].i = M.data[p].j; //��������
				T->data[q].j = M.data[p].i;
				T->data[q].e = M.data[p].e;
				q++;
			}
		}
	}
}



int main()
{
	int array1[10][10];
	int array2[10][10];
	array1[1][1] = 1;
	array2[1][2] = 2;
		
}