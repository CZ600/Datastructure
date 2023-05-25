#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

#define INFINITY 65535    //最大值∞
#define MAX_VERTEX_NUM 20 //最大顶点个数

typedef int Status;
typedef int VRType;
typedef char InfoType;
typedef int VertexType;
typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GraphKind; //{有向图，有向网，无向图，无向网}

typedef struct ArcCell
{
    VRType adj;     //VRType 是顶点关系类型。对无权图，用0或1表示相邻否；对带权图，则为权值类型
    InfoType* info; //该弧相关信息的指针
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM]; //顶点向量
    AdjMatrix arcs;                  //邻接矩阵
    int vexnum, arcnum;              //图的当前顶点数和弧数
    GraphKind kind;                  //图的种类标志
} MGraph;

typedef int Vertextype;
typedef int VRType;

int LocateVex(MGraph* G, VertexType u)
{
    int i;
    for ( i = 0; i < G->vexnum; i++)
    {
        if (G->vexs[i] == u)
        {
            return i;
        }
    }
}


void Prim(MGraph* G)
{
    VertexType u;
    int k, j;
	struct
	{
		Vertextype adjvex;
		VRType lowcost;
    }closeedge[MAX_VERTEX_NUM];  // storage the point
	k = LocateVex(G, u);
    for ( j = 0; j < G->vexnum; j++)
    {
        if (j != k)
        {
            closeedge[j].adjvex = u;
            closeedge[j].lowcost = (G->arcs[k][j]);
        }

    }
}

int main()
{

}