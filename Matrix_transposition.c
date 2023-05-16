#include<stdio.h>
#define MAXSIZE 255
typedef struct node
{
	int i, j;  //行列下表
	int e; 
}Triple;

typedef struct
{
	Triple data[MAXSIZE + 1];  // 非零元的三元数组表
	int mu, nu, tu;  // 矩阵的行数(mu)，列数(nu)，和非零元(tu)的个数
}RLSMatrix;

RLSMatrix T, M;

void TransposeSMatrix(RLSMatrix M, RLSMatrix *T) {
	T->mu = M.nu;                           //T行数等于原矩阵列数
	T->nu = M.mu;                           //T列数等于原矩阵行数
	T->tu = M.tu;                           //非零元素个数相同
	if (!T->tu)  return;

	int q = 1;                 //转置矩阵中三元组下标
	for (int col = 1; col <= M.nu; ++col) {  //枚举每一列
		for (int p = 1; p <= M.tu; ++p) {    //查找M中处于该列的非零元
			if (M.data[p].j == col) {
				T->data[q].i = M.data[p].j; //互换行列
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