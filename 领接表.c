#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXSIZE 100
#define MaxVertexNum 100

//---------------------------��Ҫʵ�ֵĲ���---------------------------
//int CreateALGraph(ALGraph* G, int numEdge, int numVer, char Vdata[], int Edata[]);
int CreateGraph(ALGraph* G, int kind, int vexnum, int edgenum);
int InsertVex(ALGraph* G, VertexType v);
//int insertArc(G, v, w);
int DeleteVex(ALGraph* G, VertexType v);
//int DeleteArc(G, v, w);

//-------------------------�ڽӱ�Ķ���-------------------------------
typedef char VertexType;  // ��������
typedef int InfoType;  // ����Ȩֵ����

//�߱���
typedef struct EdgeNode
{
	int adjvex;  // ָ��ı߽ڵ���±�
	InfoType* info;
	struct EdgeNode* next;  // ָ����һ������ָ��
}EdgeNode;

//�������
typedef struct VertexNode
{
	VertexType data; //�����򣬴洢������Ϣ
	EdgeNode* firstedge;  // �߱�ͷָ��
}VertexNode, AdjList[MAXSIZE];

//��ӱ�
typedef struct ALGraph
{
	AdjList adjList;
	int vexnum, edgenum;  // ͼ�е�ǰ�Ķ������ͱ���
	int kind;  // ͼ�������־
}ALGraph;

//-----------------------------����ͼG-------------------------------

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


		 // ����ڵ���Ϣ
		 G.adjList[0].data = 'abc';
		 G.adjList[1].data = 'bcd';
		 G.adjList[2].data = 'cde';
		 G.adjList[3].data = 'def';
}

//------------------------ʵ�ֲ�������---------------------------------
//����ͼ
int CreateGraph(ALGraph* G, int kind, int vexnum, int edgenum)
{ // �����ڽӱ�洢�ṹ,����û�������Ϣ��ͼG(��һ����������4��ͼ)
	int i, j, k;
	int w; // Ȩֵ
	VertexType va, vb;
	EdgeNode* p;
	// printf("������ͼ������(����ͼ:0,������:1,����ͼ:2,������:3): ");
	G->kind = kind;
	G->edgenum = edgenum;
	G->vexnum = vexnum;
	printf("������%d�������ֵ(<%d���ַ�):\n", G->vexnum,MAXSIZE);

	for (i = 0; i < G->vexnum; ++i) // ���춥������
	{
		scanf("%d", G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}
	if (G->kind == 1 || G->kind == 3) // ��
		printf("��˳������ÿ����(��)��Ȩֵ����β�ͻ�ͷ(�Կո���Ϊ���):\n");
	else // ͼ
		printf("��˳������ÿ����(��)�Ļ�β�ͻ�ͷ(�Կո���Ϊ���):\n");
	for (k = 0; k < G->edgenum; ++k) // �����������
	{
		if (G->kind == 1 || G->kind == 3) // ��
			scanf("%d%s%s", &w, va, vb);
		else // ͼ
			scanf("%s%s", va, vb);
		i = LocateVex(*G, va); // ��β
		j = LocateVex(*G, vb); // ��ͷ
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex = j;
		if (G->kind == 1 || G->kind == 3) // ��
		{
			p->info = (int*)malloc(sizeof(int));
			*(p->info) = w;
		}
		else
			p->info = NULL; // ͼ
		p->next = G.vertices[i].firstarc; // ���ڱ�ͷ
		G.vertices[i].firstarc = p;
		if (G->kind >= 2) // ����ͼ����,�����ڶ�������
		{
			p = (EdgeNode*)malloc(sizeof(EdgeNode));
			p->adjvex = i;
			if (G->kind == 3) // ������
			{
				p->info = (int*)malloc(sizeof(int));
				*(p->info) = w;
			}
			else
				p->info = NULL; // ����ͼ
			p->next = G->adjList[i].firstedge; // ���ڱ�ͷ
			G->adjList[j].firstedge = p;
		}
	}
	return 1;
}

//�򻯰��


//��λ�ڵ�
int LocateVex(ALGraph G, VertexType u)
{ // ��ʼ����: ͼG����,u��G�ж�������ͬ����
  // �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (strcmp(u, G.adjList[i].data) == 0)
			return i;
	return -1;
}

//��ӽڵ�
int InsertVex(ALGraph* G, VertexType v)
{
	strcpy(G->adjList[G->vexnum].data, v);  // �����µĶ�������
	G->adjList[G->vexnum].firstedge = NULL;
	G->vexnum++;
	return 1;
}

//ɾ���ڵ�
int DeleteVex(ALGraph* G, VertexType v)
{
	int i, j;
	EdgeNode* p, * q;
	j = LocateVex(*G, v);  // ��ȡ����v�����
	if (j < 0) return _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR;
	// ɾ����pΪ���Ȼ�����ȵĻ�
	p = G->adjList[j].firstedge;
	while (p)
	{
		q = p;
		p = p->next;
		//��������磬���ͷ����Ȩֵ��Ϣ
		if (G->kind % 2)
		{
			free(q->info);
			free(q);
			G->edgenum--;  // the number of edge minus 1
		}
		G->vexnum--;  // the number of Vertexes minus 1
		for (i = j; i < G->vexnum; i++)
		{
			G->adjList[i] = G->adjList[i + 1];  // ����v����Ķ�����ǰ�ƶ�
		}
		// ɾ����vΪ��ȵĻ����߱ߣ��ұ�Ҫʱ�޸ı��㶥��λ�õ�ֵ
		for (i = 0; i < G->vexnum; i++)  // �������еĶ���
		{
			p = G->adjList[i].firstedge;  // ָ��ý��ĵ�һ�������߱�
			while (p)  // �����ڻ����߱ߵ�ʱ��
			{
				if (p->adjvex == j)
				{
					if (p == G->adjList[i].firstedge)  // �����ɾ�����ǵ�һ���ڵ�
					{
						G->adjList[i].firstedge = p->next;
						if (G->kind % 2)  // �ж��Ƿ�Ϊ����
						{
							free(p->info);  // ɾ��Ȩֵ��Ϣ
						}
						free(p);
						p = G->adjList->firstedge;  // ��ʱpָ����һ�����
						if (G->kind < 2)  // ����
						{
							G->edgenum--;  //������ȥ1
						}
					}
					else
					{
						q->next = p->next;
						// ��ɾ���Ľ�㲻�ǵ�һ�����
						if (G->kind % 2)  // ��Ȩֵ
						{
							free(p->info);
						}
						free(p);
						p = q->next;
						if (G->kind < 2)  // ����
						{
							G->edgenum--;
						}
					}
				}
				else
				{
					if (p->adjvex > j)
					{
						p->adjvex--;  // �޸ı���Ķ���λ��ֵ����ţ�
						q = p;
						p = p->next;
					}
				}
			}
		}
	}
	return 1;
}

