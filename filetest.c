#include<stdlib.h>
#include<stdio.h>

int main()
{
	int mapdata[3][3];
	int i, j;
	int k = 0;
	int count = 0;  //统计文件中字符个数
	int sum_row;  //统计文件中字符个数
	int flag = 0;  //用于暂时将文件内容保存
	FILE* fp;    //文件指针
	FILE* fp1;
	fp = fopen("datanumber.txt", "r");   //打开文件，只读，argv[1]代表从命令行输入的文件名称，即运行.exe程序时输入的第二个参数
	fp1 = fopen("datanumber.txt", "r");   //再次打开文件，（第一次打开文件用于统计文件的行数，即数据的个数）用于将文件内容保存到指针数组里
	// fp2 = fopen("test1.txt", "w");   //打开文件，只写，用于将数组内容重新保存到另一个文件中
	if (fp == NULL)    //打开文件失败
	{
		printf("File cannot open! ");
		//exit;  
		return 0;
	}
	i = 0;
	while (!feof(fp))  //读文件，直到文件末尾
	{
		fscanf(fp, "%d %d %d", &mapdata[i][0], &mapdata[i][1], &mapdata[i][2]);
		i++;
		count++;
	}
	k = i;
	sum_row = count + 1; //加上文件最后一行，即为文件总的行数
	printf("文件行数为：%d", sum_row);  //统计文件行数，因为每行只有一个数，所以即统计文件中有多少个数
	printf("\n");

	printf("文件内容为：\n");

	
	for (i = 0; i < k; i++)  //循环打印保存到指针数组中的数据
	{
		for (j = 0; j < k; j++)
		{
			printf("%d\t", mapdata[i][j]);  //打印
		}
		printf("\n");
		
	}
	fclose(fp);  //关闭文件，释放指向文件的指针
	fclose(fp1);  //关闭文件，释放指向文件的指针
	return 0;
}