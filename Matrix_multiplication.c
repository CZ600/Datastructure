#include<stdio.h>
#define MAXSIZE 255

typedef struct
{
	int i, j;
	int e;
}Triple;

typedef struct
{
	int Data[MAXSIZE];
	int mu, nu, tu;  // ������������������ͷ���Ԫ�ĸ���
}RLSMatrix;

RLSMatrix M, N, Q;


int MatrixMultiplication(RLSMatrix M, RLSMatrix N, RLSMatrix *Q)
{
	int ctemp[MAXSIZE] = {};
	if (M.mu != N.nu)
	{
		return -1;
	}
	Q->mu = M.mu;
	Q->nu = N.nu;
	Q->tu = 0;
	int arow;
	if (M.tu * N.tu != 0)  // ����Q�Ƿ������
	{
		for (arow = 1; arow <= M.mu; ++arow) ctemp[arow] = 0;

	}
}



int main()
{

}