#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXSIZE 100
#define MaxVertexNum 100


//------------------------��Ӿ���----------------------------
typedef char Vertextype;   // �������������
typedef int InfoType;  // �ߵ���������

typedef struct  // �����ٽ־���
{
	Vertextype Vex[MaxVertexNum];  // �����
	InfoType Edge[MaxVertexNum][MaxVertexNum];  // �ڽӾ���
	int vexnum,  //ͼ��ǰ�Ķ�����
		arcnum;  // ͼ��ǰ�Ļ���
}MGraph;  // ����






//-------------------------��Ӿ�������ͼ���Ĵ��������-----------------
void create_Graph(MGraph* G)
{
	int i, j;
	int start, end;  // �ߵ��������յ����
	int numV, numE;  //
	int w;  // ���ϵ�Ȩֵ
	printf_s("������������������ͼ�Ķ������ͱ������ÿո������");
	scanf_s("%d%d", &numV, &numE);
	G->vexnum = numV;
	G->arcnum = numE;

	printf_s("\n");

	//ͼ�ĳ�ʼ��
	//���������е�ÿ��Ԫ��
	for (i = 0; i < G->vexnum; j++)  // vexnum �������
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

	//������Ϣ���붥���
	for (i = 0; i < G->vexnum; i++)
	{
		printf("�������%d���������Ϣ", i + 1);
		scanf_s("%d", &G->Vex[i]);
	}
	printf_s("\n");
	//��������ͼ�ߵ���Ϣ
	for (i = 0; i < G->arcnum; i++)
	{
		printf("������ߵ������ţ� �յ���ţ� Ȩֵ���ÿո��������");
		scanf_s("%d%d%d", &start, &end, &w);
		G->Edge[start - 1][end - 1] = w;
		G->Edge[end - 1][start - 1] = w;  //����ͼ���жԳ���

	}
	
}//����ͼ���ƣ�����û�жԳ���


//-------------------------����ͼ------------------------------

int visit(MGraph* G,int v)
{
	int i;
	i = G->Vex[v];
	printf("c");
	return i;
}

//-----------------------��ѯ����λ��--------------------------
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
//DFS �㷨

bool visted[MaxVertexNum];  // ���ʱ������

int DFS(MGraph* G, int v)
{
	int w;
	visit(&G, v);  // ���ʶ���
	visted[v] = true; // �����Ѿ����ʵı��
	// FirstNeighbor(G, v):��ͼG�ж���v�ĵ�һ����Ӵ��㣬�����򷵻ض���ã�����
	// NextNeigthbor(G,v,w):����ͼG�ж���w�Ƕ���v��һ����ӵ㣬���س���w��Ķ���v

}