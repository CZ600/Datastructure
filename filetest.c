#include<stdlib.h>
#include<stdio.h>

int main()
{
	int mapdata[3][3];
	int i, j;
	int k = 0;
	int count = 0;  //ͳ���ļ����ַ�����
	int sum_row;  //ͳ���ļ����ַ�����
	int flag = 0;  //������ʱ���ļ����ݱ���
	FILE* fp;    //�ļ�ָ��
	FILE* fp1;
	fp = fopen("datanumber.txt", "r");   //���ļ���ֻ����argv[1]�����������������ļ����ƣ�������.exe����ʱ����ĵڶ�������
	fp1 = fopen("datanumber.txt", "r");   //�ٴδ��ļ�������һ�δ��ļ�����ͳ���ļ��������������ݵĸ��������ڽ��ļ����ݱ��浽ָ��������
	// fp2 = fopen("test1.txt", "w");   //���ļ���ֻд�����ڽ������������±��浽��һ���ļ���
	if (fp == NULL)    //���ļ�ʧ��
	{
		printf("File cannot open! ");
		//exit;  
		return 0;
	}
	i = 0;
	while (!feof(fp))  //���ļ���ֱ���ļ�ĩβ
	{
		fscanf(fp, "%d %d %d", &mapdata[i][0], &mapdata[i][1], &mapdata[i][2]);
		i++;
		count++;
	}
	k = i;
	sum_row = count + 1; //�����ļ����һ�У���Ϊ�ļ��ܵ�����
	printf("�ļ�����Ϊ��%d", sum_row);  //ͳ���ļ���������Ϊÿ��ֻ��һ���������Լ�ͳ���ļ����ж��ٸ���
	printf("\n");

	printf("�ļ�����Ϊ��\n");

	
	for (i = 0; i < k; i++)  //ѭ����ӡ���浽ָ�������е�����
	{
		for (j = 0; j < k; j++)
		{
			printf("%d\t", mapdata[i][j]);  //��ӡ
		}
		printf("\n");
		
	}
	fclose(fp);  //�ر��ļ����ͷ�ָ���ļ���ָ��
	fclose(fp1);  //�ر��ļ����ͷ�ָ���ļ���ָ��
	return 0;
}