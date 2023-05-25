#include <bits/stdc++.h>
using namespace std;
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

typedef struct
{
    VertexType adjvex;
    VRType lowcost;
} CLOSEDGE;

/*******************************��������****************************************/
Status CreateUDN(MGraph* G);
//����������
int LocateVex(MGraph G, VertexType v);
//ȷ��v��G�е�λ��
int minimum(CLOSEDGE closedge[], int n);
//������С���ӵĶ������
void MiniSpanTree_PRIM(MGraph G, VertexType u);
//������ķ�㷨�ӵ�u���������������G����С������T�����T�ĸ�����
//��¼�Ӷ��㼯U��V-U�Ĵ�����С�ıߵĸ������鶨��
/*******************************��������****************************************/
Status CreateUDN(MGraph* G)
{
    printf("\n����������\n");
    int i, j, k;       //i,j,k���ڼ���
    int w;             //Ȩ��
    VertexType v1, v2; //��ͷ����β

    printf("�����붥�������");
    scanf("%d", &(*G).vexnum);
    printf("�����뻡������");
    scanf("%d", &(*G).arcnum);
    //�ٶ���ͼ����������Ϣ
    int IncInfo = 0;

    for (i = 0; i < (*G).vexnum; i++)
    { //���춥������
        printf("������G.vexs[%d] = ", i);
        scanf("%d", &(*G).vexs[i]);
    } //for

    for (i = 0; i < (*G).vexnum; i++) //��ʼ���ڽӾ���
        for (j = 0; j < (*G).vexnum; j++)
        {
            (*G).arcs[i][j].adj = INFINITY; //������
            (*G).arcs[i][j].info = NULL;
        }

    for (k = 0; k < (*G).arcnum; k++)
    {                                   //�����ڽӾ���
        printf("�����뻡ͷ(��ʼ��)��"); //����һ������ʼ����յ�
        scanf("%d", &v1);
        printf("�����뻡β(�ն˵�)��");
        scanf("%d", &v2);
        printf("������Ȩ�أ�");
        scanf("%d", &w);

        i = LocateVex(*G, v1);
        j = LocateVex(*G, v2);

        if (i >= 0 && j >= 0)
            (*G).arcs[i][j].adj = (*G).arcs[j][i].adj = w; //��<v1,v2>�ĶԳƻ�<v2,v1>

        //��������û����е������Ϣ
    }
    (*G).kind = UDN;
    return OK;
}

int LocateVex(MGraph G, VertexType v)
{
    int ct;
    for (ct = 0; ct < G.vexnum; ct++)
        if (G.vexs[ct] == v)
            return ct;
    return -1;
}

int minimum(CLOSEDGE closedge[], int n)
{
    int i = 0, j, min, k;
    while (!closedge[i].lowcost)
        i++;
    min = closedge[i].lowcost;
    k = i;
    for (j = 1; j < n; j++)
        if (closedge[j].lowcost)
            if (min > closedge[j].lowcost)
            {
                min = closedge[j].lowcost;
                k = j;
            } //if
    return k;
}

void MiniSpanTree_PRIM(MGraph G, VertexType u)
{
    CLOSEDGE closedge[G.vexnum + 1];
    int k, j, i;

    k = LocateVex(G, u);
    for (j = 0; j < G.vexnum; ++j)
        if (j != k)
        { //���������ʼ��
            closedge[j].adjvex = u;
            closedge[j].lowcost = G.arcs[k][j].adj;
        } //if

    closedge[k].lowcost = 0; //��ʼ��U = {u}
    for (i = 1; i < G.vexnum; ++i)
    { //ѡ������G.vexnum-1������

        k = minimum(closedge, G.vexnum);                    //���T����һ����㣺��k������
        printf("(%d,%d)\n", closedge[k].adjvex, G.vexs[k]); //����������ı�

        closedge[k].lowcost = 0; //��k���㲢��U��

        for (j = 0; j < G.vexnum; ++j)
        {
            if (G.arcs[k][j].adj < closedge[j].lowcost)
            { //�¶��㲢��U��������ѡ����С��
                closedge[j].adjvex = G.vexs[k];
                closedge[j].lowcost = G.arcs[k][j].adj;
            } //if
        }     //for
    }         //for
}

/*******************************����������**************************************/

int main()
{
    MGraph G;
    printf("P174 ͼ7.16��a��\n");
    CreateUDN(&G);
    printf("\n����������ϵ�5����Ϊ��\n");
    MiniSpanTree_PRIM(G, 1);
    return 0;
}