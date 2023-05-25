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

#define INFINITY 65535    //���ֵ��
#define MAX_VERTEX_NUM 20 //��󶥵����

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
} GraphKind; //{����ͼ��������������ͼ��������}

typedef struct ArcCell
{
    VRType adj;     //VRType �Ƕ����ϵ���͡�����Ȩͼ����0��1��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ����
    InfoType* info; //�û������Ϣ��ָ��
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM]; //��������
    AdjMatrix arcs;                  //�ڽӾ���
    int vexnum, arcnum;              //ͼ�ĵ�ǰ�������ͻ���
    GraphKind kind;                  //ͼ�������־
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