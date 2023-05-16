#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXSIZE 100
#define MaxVertexNum 100


//------------------------领接矩阵----------------------------
typedef char Vertextype;   // 顶点的数据类型
typedef int InfoType;  // 边的数据类型

typedef struct  // 定义临街矩阵
{
	Vertextype Vex[MaxVertexNum];  // 顶点表
	InfoType Edge[MaxVertexNum][MaxVertexNum];  // 邻接矩阵
	int vexnum,  //图当前的顶点数
		arcnum;  // 图当前的弧数
}MGraph;  // 命名






//-------------------------领接矩阵（无向图）的创建与访问-----------------
void create_Graph(MGraph* G)
{
	int i, j;
	int start, end;  // 边的起点序号终点序号
	int numV, numE;  //
	int w;  // 边上的权值
	printf_s("请输入所创建的无向图的顶点树和边数，用空格隔开：");
	scanf_s("%d%d", &numV, &numE);
	G->vexnum = numV;
	G->arcnum = numE;

	printf_s("\n");

	//图的初始化
	//遍历矩阵中的每个元素
	for (i = 0; i < G->vexnum; j++)  // vexnum 顶点个数
	{
		for ( j = 0; j < G->vexnum; j++)  
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
		printf("请输入第%d个顶点的信息", i + 1);
		scanf_s("%d", &G->Vex[i]);
	}
	printf_s("\n");
	//输入无向图边的信息
	for (i = 0; i < G->arcnum; i++)
	{
		printf("请输入边的起点序号， 终点序号， 权值（用空格隔开）：");
		scanf_s("%d%d%d", &start, &end, &w);
		G->Edge[start - 1][end - 1] = w;
		G->Edge[end - 1][start - 1] = w;  //无向图具有对称性

	}
	
}//有向图类似，但是没有对称性


//-------------------------访问图------------------------------

int visit(MGraph* G,int v)
{
	int i;
	i = G->Vex[v];
	printf("c");
	return i;
}

//-----------------------查询顶点位置--------------------------
int LocateVex(MGraph G, Vertextype u)
{
	int i;
	for ( i = 0; i < G.vexnum; i++)
	{
		if (u == G.Vex[i])
		{
			return i;
		}
		else
		{
			return -1;
		}

	}

}

//




// depth first search
//DFS 算法

bool visted[MaxVertexNum];  // 访问标记数组

int DFS(MGraph* G, int v)
{
	int w;
	visit(&G, v);  // 访问顶点
	visted[v] = true; // 设置已经访问的标记
	// FirstNeighbor(G, v):求图G中顶点v的第一个领接带你，若有则返回顶点好，否则。
	// NextNeigthbor(G,v,w):假设图G中顶点w是顶点v的一个领接点，返回除了w外的顶点v

}