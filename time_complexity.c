#include<stdio.h>
#include<time.h>

int main()
{
	int arrary[100];
}

int MaxSubsquSum(int A[], int N)
{
	int i = N;
	int MaxSum = 0, ThisSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum += A[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		else
		{

		}
	}
}