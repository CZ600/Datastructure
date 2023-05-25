#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>				//用到了定时函数sleep()
#include <math.h>

#define MaxVertexNum 100
#define MAXSIZE 255
#define INF (~(0x1<<31))        // 最大值(即0X7FFFFFFF) 表示一个非常大的数，约等于无穷大

//访问标志数组
int visited[MaxVertexNum];

//-------------------------------------the part of base operation function------------------------------------
//定义顶点的数据类型
typedef struct Vertextype
{
	char name[MAXSIZE];
	char information[MAXSIZE];
	char buildings[MAXSIZE];
}Vertextype;


//交通工具数据类型
typedef struct vehicle
{
	char name[MAXSIZE];
	int speed;
}vehicle;

//定义领接矩阵
typedef struct MGraph
{
	Vertextype Vex[MaxVertexNum];  // 顶点表
	int Edge[3][3];   // 邻接矩阵
	int vexnum, arcnum;  // 图当前的顶点树和弧数
}MGraph;

// 栈
typedef struct
{
	int data[MAXSIZE];
	int top;
}SqStack;

//------------------------------------- declaration ----------------------------------------------------------
int LocateVex(MGraph G, Vertextype u);
int FirstAdjVex(MGraph G, Vertextype v);
int NextAdjVex(MGraph G, Vertextype v, Vertextype w);
Vertextype GetVex(MGraph G, int v);
void create_Graph(MGraph* G, Vertextype pointData[], int edgeData[][3]);
int visitFunc(MGraph* G, int v);
void DFS(MGraph* G, int v, int visited[]);
void DFStraveler(MGraph G, int x);
void BFS(MGraph G, int v);
void dijkstra(MGraph G, int v0, int prev[], int dist[]);
void color(short x);
void StartMenu(MGraph G);
void search(MGraph G);
void navigation(MGraph G);
void Init_SeqStack(SqStack** s);
int Empty_SeqStack(SqStack* s);
void Push_Stack(SqStack* s, int x);
void Pop_SeqStack(SqStack* s, int* x);
void Top_SeqStack(SqStack* s, int* x);
void Output_SeqStack(SqStack* s);
void filereadNUM(int mapdata[3][3]);

/*
链栈的节点的定义
*/

// 栈初始化
void Init_SeqStack(SqStack** s)
{
	// 开辟一块空间，并将该空间的地址赋给s
	*s = (SqStack*)malloc(sizeof(SqStack));
	(*s)->top = -1;
}

// 判栈为空
int Empty_SeqStack(SqStack* s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

// 入栈
void Push_Stack(SqStack* s, int x)
{
	if (s->top == MAXSIZE - 1)
		printf("Stack is full!\n");
	else
	{
		s->top++;
		s->data[s->top] = x;
	}
}

// 出栈
void Pop_SeqStack(SqStack* s, int* x)
{
	if (s->top == -1)
		printf("栈为空!\n");
	else
	{
		*x = s->data[s->top];
		s->top--;
	}
}

// 取栈顶元素
void Top_SeqStack(SqStack* s, int* x)
{
	if (s->top == -1)
		printf("栈为空!\n");
	else
	{
		*x = s->data[s->top];
		printf("出栈成功！\n");
	}
}
// 输出
void Output_SeqStack(SqStack* s)
{
	SqStack* w;
	int i;
	printf("栈中的元素有：");
	for (i = s->top; i >= 0; i--)
		printf("%d ", s->data[i]);
	printf("\n");
}

// 查询顶点位置
int LocateVex(MGraph G, Vertextype u)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (u.name == G.Vex[i].name)
		{
			return i;
		}
	}
	return -1;
}

// 获取v 的第一个领接顶点的序号，若顶点在G中没有领接顶点，则返回-1
int FirstAdjVex(MGraph G, Vertextype v)
{
	//Map G exist, and v is a point in the Map G;
	int i, j = 0, k;
	k = LocateVex(G, v);
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.Edge[k][i] != j || G.Edge[k][i] != INF)
		{
			return i;
		}
	}
	return -1;
}

//v为图G中的某个顶点，w 是v的领接顶点，返回v的（相对于w）下一个领接顶点的序号
int NextAdjVex(MGraph G, Vertextype v, Vertextype w)
{
	// 若w是v的最后一个邻接顶点,则返回-1
	int i, j = 0, k1, k2;
	k1 = LocateVex(G, v);  // k1为顶点v在图G中的序号
	k2 = LocateVex(G, w);  // k2为顶点w在图G中的序号

	for (i = k2; i < G.vexnum; i++)
	{
		if (G.Edge[k1][i] != j || G.Edge[k1][i] != INF) {
			return i;
		}
	}
	return -1;
}

// 返回v的值
// 初始条件: 图G存在，v是G中某个顶点的序号。操作结果: 返回v的值
Vertextype GetVex(MGraph G, int v)
{
	if (v >= G.vexnum || v < 0)
		exit(1);
	return G.Vex[v];
}

//存储领接关系
void create_Graph(MGraph* G, Vertextype pointData[], int edgeData[][3])
{
	int numV = 0, numE = 0;

	int i, j;
	int start, end;  // 边的起点序号终点序号 //
	int w;  // 边上的权值
	G->vexnum = numV;
	G->arcnum = numE;

	printf_s("\n");

	//图的初始化
	//遍历矩阵中的每个元素
	for (i = 0; i < G->vexnum; j++)  // vexnum 顶点个数
	{
		for (j = 0; j < G->vexnum; j++)
		{
			if (i == j)
			{
				G->Edge[i][j] = 0;
			}
			else
			{
				G->Edge[i][j] = 32767;
			}
		}
	}

	//顶点信息存入顶点表
	for (i = 0; i < G->vexnum; i++)
	{
		G->Vex[i] = pointData[i];
	}
	printf_s("\n");

	//输入无向图边的信息

	for (i = 0; i < G->arcnum; i++)
	{
		for (j = 0; j < G->arcnum; j++)
		{
			G->Edge[i][j] = edgeData[i][j];
		}
	}
}

//访问节点信息函数
int visitFunc(MGraph* G, int v)
{
	char name;
	char imformation;
	char building;
	name = G->Vex[v].name;
	imformation = G->Vex[v].information;
	building = G->Vex[v].buildings;
	printf("%s %s %s", &name, &imformation, &building);
	return 1;
}

//第一个顶点

//DFS
// 从第v个顶点出发递归地深度优先遍历图G。算法7.5
void DFS(MGraph* G, int v, int visited[])
{
	int w;
	visitFunc(G, v);
	visited[v] = 1;
	for (w = FirstAdjVex(*G, G->Vex[v]); w >= 0; w = NextAdjVex(*G, G->Vex[v], G->Vex[w]))
	{
		if (!visited[w])
		{
			DFS(G, w, visited);  // 对尚未访问的领接顶点我递归调用dfs
		}
	}
}

//DFS遍历整个图
void DFStraveler(MGraph G, int x)
{
	int w, i;
	// visited 中全部未访问
	for (i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
	}
	//dfs访问的主体部分
	for (i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			DFS(&G, i, visited);
		}
	}
	printf_s("\n");
}

//BFS算法
void BFS(MGraph G, int v)
{
	int i, j, k;
	int visited[MAXSIZE];
	int queue[MAXSIZE];
	int rear = 0, front = 0;

	for (i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
	}
	for (i = 0; i < G.vexnum; i++)
	{
		if (visited[i] != 0)
		{
			visited[i] = 1;
			visitFunc(&G, i);
			queue[rear++] = i;
		}

		while (rear != front)
		{
			j = queue[front++];  // 队列中已经有的元素出队

			for (k = FirstAdjVex(G, GetVex(G, j)); k >= 0; k = NextAdjVex(G, GetVex(G, j), GetVex(G, k)))  // 访问出队元素的所有的结点
			{
				visited[k] = 1;  // 访问标记
				visitFunc(&G, k);  //访问
				queue[rear++] = k;  // 入队
			}
		}
	}
	printf_s("\n");
}

// 求最短路径之迪杰斯特拉算法
// v0 起始顶点也就是计算vs到其他顶点的最短路径
/*
prev -- 前驱顶点数组。
即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
*/
// dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
void dijkstra(MGraph G, int v0, int prev[], int dist[])
{
	int i, j, k = 0;
	int min;
	int tmp;
	int visited[MAXSIZE];  // 标记已访问数组

	// 初始化
	// 使得dist中存入所有顶点的权值
	for (i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
		prev[i] = 0;
		dist[i] = G.Edge[v0][i];  // dist[]用于存储最短路径值
	}

	visited[v0] = 1;  // 将起始点自身设置为已经访问
	dist[v0] = 0;  // 将起始点到自身的距离设置为0

	// 遍历G.vexnum-1 次，每次找出一个顶点的最短路径值
	// 简单的说，这个循环的作用就是联通的结点里面找最短的
	for (i = 1; i < G.vexnum; i++)
	{
		// 寻找当前的最小路径
		// 也就是，在未获取最短路径的顶点中，找到vs最近的顶点k
		min = INF;
		for (j = 0; j < G.vexnum; j++)
		{
			if (visited[j] == 0 && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}
	}
	// 好了，现在你已经找到了与v0联通的结点中最短的距离的那个了！
	// 记k为目前已知的最短路径
	visited[k] = -1;

	// 修正当前的最短路径和前驱顶点，也就是当已经更新未获取最短路径顶点的最短路径和前驱顶点
	for (j = 0; j < G.vexnum; j++)
	{
		tmp = (G.Edge[k][j] == INF ? INF : (min + G.Edge[k][j]));  // 防止越界
		if (visited[j] == 0 && (tmp < dist[j]))
		{
			dist[j] = tmp;
			prev[j] = k;
		}
	}

	// 打印最终结果
	printf_s("dijkstra(%c):\n", (char)(G.Vex[v0]).name);
	for (i = 0; i < G.vexnum; i++)
	{
		printf_s("shortest(%c, %c) = %d\n", (char)(G.Vex[v0].name), (char)(G.Vex[i].name), dist[i]);
	}
}


//-----------------------------the functional function ----------------------------------
// 颜色设置函数
/*
color table
0 = 黑色       8 = 灰色
1 = 蓝色       9 = 淡蓝色
2 = 绿色       A = 淡绿色
3 = 浅绿色     B = 淡浅绿色
4 = 红色       C = 淡红色
5 = 紫色       D = 淡紫色
6 = 黄色       E = 淡黄色
7 = 白色       F = 亮白色

*/
void color(short x)
{
	if (x >= 0 && x <= 15)//参数在0-15的范围颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色
	else//默认的颜色白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//开始界面
void StartMenu(MGraph G)
{
	int key;
	color(4);  // red
	printf_s("Welcome to use the nevigation system of Nanjing Normal University\n");

	while (1)
	{
		printf_s("You can chose what to do next(inpout the number):\n");
		printf_s("1.Search the position of a point\n");
		printf_s("2.Show you all the points\n");
		printf_s("3.Help you find the shortest path between two points\n");
		printf_s("4.Finish!\n");
		scanf_s("%d", &key);
		switch (key)
		{
		case 1:
			search(G);
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			exit(-1);
			break;
		}
	}
}

void search(MGraph G)
{
	char PointName[MAXSIZE];
	char name[MAXSIZE], buildings[MAXSIZE], imformation[MAXSIZE];
	system("cls");			//清屏
	printf_s("Please input the name of point:\n");
	gets(PointName);
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.Vex[i].name == PointName)
		{
			strcpy(name, G.Vex[i].name);
			strcpy(buildings, G.Vex[i].buildings);
			strcpy(imformation, G.Vex->information);

			printf_s("%s, %s, %s", name, buildings, imformation);
		}
	}
}

void navigation(MGraph G)
{
	char start[10];
	char end[10];
	system("cls");			//清屏
	printf_s("Please input the name of start:\n");
	gets(start);
	printf_s("Please input the name of end:\n");
	gets(end);
}

void filereadNUM(int mapdata[3][3])
{
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


}

void filereadCHR(Vertextype data[])
{
	int i, j;
	FILE* fp;
	fp = fopen("imformation", 'r');
	if (fp == NULL)    //打开文件失败
	{
		printf("File cannot open! ");
		//exit;  
		return 0;
	}
	i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s", data[i].buildings, data[i].information, data[i].name);
		i++;
	}

}

//---------------------------------- main function -------------------------------------
int main()
{
	SqStack NodeData;
	MGraph CampusData;
	MGraph* campus = &CampusData;
	campus = (MGraph*)malloc(sizeof(MGraph));
	Init_SeqStack(&NodeData);
	int i = 0;
	int mapdata[3][3];

	//存储数据
	Vertextype points[100];
	
		/*
		=
	{
		{ "学行楼","北区主要教学楼","学行楼" },
		{ "四号门","通往仙林宾馆，出校，北区，东区","仙林宾馆" },
		{ "东南门","东区主要出口，通往北区、网球场、东区住宿区","网球场 住宿区"}
	};
		*/
		
	filereadNUM(mapdata);

	//数据存储图的初始化
	create_Graph(campus, points, edgedata);

	StartMenu(*campus);

	free(campus);
	return 0;
}