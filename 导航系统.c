#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <graphics.h>              // 引用图形库头文件
#include <conio.h>
#include <windows.h>				//用到了定时函数sleep()
#include <math.h>

#define MaxVertexNum 100
#define MAXSIZE 255
#define INF (~(0x1<<31))        // 最大值(即0X7FFFFFFF) 表示一个非常大的数，约等于无穷大

//-------------------------------------the part of base operation function------------------------------------
//定义顶点的数据类型
typedef struct Vertextype
{
	char name[MAXSIZE];
	char information[MAXSIZE];
	char buildings[MAXSIZE];
}Vertextype;

//边的权值
typedef int InfoType;

//交通工具数据类型
typedef struct vehicle
{
	char name[MAXSIZE];
	int speed;
};

//定义领接矩阵
typedef struct MGraph
{
	Vertextype Vex[MaxVertexNum];  // 顶点表
	InfoType Edge[3][3];   // 邻接矩阵
	int vexnum, arcnum;  // 图当前的顶点树和弧数
}MGraph;

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
void create_Graph(MGraph* G, Vertextype pointData[], InfoType edgeData[][3])
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

//访问标志数组
int visited[MaxVertexNum];

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
	Vertextype w1, v1;
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
//开始界面
void StartMenu(MGraph G)
{
	int key;
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
		default:
			exit(-1);
			break;
		}


	}
	
}

void search(MGraph G)
{
	char PointName[MAXSIZE];
	printf_s("Please input the name of point:\n");
	gets(PointName);
}

void navigation(MGraph G)
{
	char start[10];
	char end[10];
	printf_s("Please input the name of start:\n");
	gets(start);
	printf_s("Please input the name of end:\n");
	gets(end);
}

//---------------------------------- main function -------------------------------------
int main()
{
	MGraph Campus;
	//存储数据
	Vertextype points[100] =
	{
		{ "学行楼","北区主要教学楼","学行楼" },
		{ "四号门","通往仙林宾馆，出校，北区，东区","仙林宾馆" },
		{ "东南门","东区主要出口，通往北区、网球场、东区住宿区","网球场 住宿区"}
	};

	//定义领接关系表
	InfoType edgedata[3][3] =
	{
		{0, 625, INF},
		{625, 0, 475},
		{INF, 475, 0}
	};

	//数据存储图的初始化
	create_Graph(&Campus, points, edgedata);

	return 0;
}