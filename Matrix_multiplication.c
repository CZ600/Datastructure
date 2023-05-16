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
	int mu, nu, tu;  // 矩阵的行数，列数，和非零元的个数
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
	if (M.tu * N.tu != 0)  // 假如Q是非零矩阵
	{
		for (arow = 1; arow <= M.mu; ++arow) ctemp[arow] = 0;

	}
}



int main()
{

}