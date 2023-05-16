#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXSIZE 100
#define MaxVertexNum 100

//---------------------------需要实现的操作---------------------------
//int CreateALGraph(ALGraph* G, int numEdge, int numVer, char Vdata[], int Edata[]);
int CreateGraph(ALGraph* G, int kind, int vexnum, int edgenum);
int InsertVex(ALGraph* G, VertexType v);
//int insertArc(G, v, w);
int DeleteVex(ALGraph* G, VertexType v);
//int DeleteArc(G, v, w);

//-------------------------邻接表的定义-------------------------------
typedef char VertexType;  // 顶点类型
typedef int InfoType;  // 定义权值类型

//边表结点
typedef struct EdgeNode
{
	int adjvex;  // 指向的边节点的下标
	InfoType* info;
	struct EdgeNode* next;  // 指向下一条弧的指针
}EdgeNode;

//顶点表结点
typedef struct VertexNode
{
	VertexType data; //顶点域，存储顶点信息
	EdgeNode* firstedge;  // 边表头指针
}VertexNode, AdjList[MAXSIZE];

//领接表
typedef struct ALGraph
{
	AdjList adjList;
	int vexnum, edgenum;  // 图中当前的顶点树和边数
	int kind;  // 图的种类标志
}ALGraph;

//-----------------------------定义图G-------------------------------

int main()
{
	ALGraph G;
	char nodeData[4] = { 'a', 'b', 'c', 'd' };
	int numE = 5, numV = 4;
	int edgeData[4][4] = 
	{
		1, 1, 1, 1,
		1, 0, 1, 1,
		1, 0, 0, 1,
		1, 1, 0, 0
	};


		 // 输入节点信息
		 G.adjList[0].data = 'abc';
		 G.adjList[1].data = 'bcd';
		 G.adjList[2].data = 'cde';
		 G.adjList[3].data = 'def';
}

//------------------------实现操作函数---------------------------------
//创建图
int CreateGraph(ALGraph* G, int kind, int vexnum, int edgenum)
{ // 采用邻接表存储结构,构造没有相关信息的图G(用一个函数构造4种图)
	int i, j, k;
	int w; // 权值
	VertexType va, vb;
	EdgeNode* p;
	// printf("请输入图的类型(有向图:0,有向网:1,无向图:2,无向网:3): ");
	G->kind = kind;
	G->edgenum = edgenum;
	G->vexnum = vexnum;
	printf("请输入%d个顶点的值(<%d个字符):\n", G->vexnum,MAXSIZE);

	for (i = 0; i < G->vexnum; ++i) // 构造顶点向量
	{
		scanf("%d", G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}
	if (G->kind == 1 || G->kind == 3) // 网
		printf("请顺序输入每条弧(边)的权值、弧尾和弧头(以空格作为间隔):\n");
	else // 图
		printf("请顺序输入每条弧(边)的弧尾和弧头(以空格作为间隔):\n");
	for (k = 0; k < G->edgenum; ++k) // 构造表结点链表
	{
		if (G->kind == 1 || G->kind == 3) // 网
			scanf("%d%s%s", &w, va, vb);
		else // 图
			scanf("%s%s", va, vb);
		i = LocateVex(*G, va); // 弧尾
		j = LocateVex(*G, vb); // 弧头
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex = j;
		if (G->kind == 1 || G->kind == 3) // 网
		{
			p->info = (int*)malloc(sizeof(int));
			*(p->info) = w;
		}
		else
			p->info = NULL; // 图
		p->next = G.vertices[i].firstarc; // 插在表头
		G.vertices[i].firstarc = p;
		if (G->kind >= 2) // 无向图或网,产生第二个表结点
		{
			p = (EdgeNode*)malloc(sizeof(EdgeNode));
			p->adjvex = i;
			if (G->kind == 3) // 无向网
			{
				p->info = (int*)malloc(sizeof(int));
				*(p->info) = w;
			}
			else
				p->info = NULL; // 无向图
			p->next = G->adjList[i].firstedge; // 插在表头
			G->adjList[j].firstedge = p;
		}
	}
	return 1;
}

//简化版的


//定位节点
int LocateVex(ALGraph G, VertexType u)
{ // 初始条件: 图G存在,u和G中顶点有相同特征
  // 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (strcmp(u, G.adjList[i].data) == 0)
			return i;
	return -1;
}

//添加节点
int InsertVex(ALGraph* G, VertexType v)
{
	strcpy(G->adjList[G->vexnum].data, v);  // 构造新的顶点向量
	G->adjList[G->vexnum].firstedge = NULL;
	G->vexnum++;
	return 1;
}

//删除节点
int DeleteVex(ALGraph* G, VertexType v)
{
	int i, j;
	EdgeNode* p, * q;
	j = LocateVex(*G, v);  // 获取顶点v的序号
	if (j < 0) return _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
	// 删除以p为出度或者入度的弧
	p = G->adjList[j].firstedge;
	while (p)
	{
		q = p;
		p = p->next;
		//如果是网络，就释放清除权值信息
		if (G->kind % 2)
		{
			free(q->info);
			free(q);
			G->edgenum--;  // the number of edge minus 1
		}
		G->vexnum--;  // the number of Vertexes minus 1
		for (i = j; i < G->vexnum; i++)
		{
			G->adjList[i] = G->adjList[i + 1];  // 顶点v后面的顶点向前移动
		}
		// 删除以v为入度的弧或者边，且必要时修改表结点顶点位置的值
		for (i = 0; i < G->vexnum; i++)  // 遍历所有的顶点
		{
			p = G->adjList[i].firstedge;  // 指向该结点的第一条弧或者边
			while (p)  // 当存在弧或者边的时候
			{
				if (p->adjvex == j)
				{
					if (p == G->adjList[i].firstedge)  // 如果待删除的是第一个节点
					{
						G->adjList[i].firstedge = p->next;
						if (G->kind % 2)  // 判断是否为网络
						{
							free(p->info);  // 删除权值信息
						}
						free(p);
						p = G->adjList->firstedge;  // 此时p指向下一个结点
						if (G->kind < 2)  // 有向
						{
							G->edgenum--;  //边数减去1
						}
					}
					else
					{
						q->next = p->next;
						// 待删除的结点不是第一个结点
						if (G->kind % 2)  // 有权值
						{
							free(p->info);
						}
						free(p);
						p = q->next;
						if (G->kind < 2)  // 有向
						{
							G->edgenum--;
						}
					}
				}
				else
				{
					if (p->adjvex > j)
					{
						p->adjvex--;  // 修改表结点的顶点位置值（序号）
						q = p;
						p = p->next;
					}
				}
			}
		}
	}
	return 1;
}

