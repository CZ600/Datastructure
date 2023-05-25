#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>				//�õ��˶�ʱ����sleep()
#include <math.h>

#define MaxVertexNum 100
#define MAXSIZE 255
#define INF (~(0x1<<31))        // ���ֵ(��0X7FFFFFFF) ��ʾһ���ǳ��������Լ���������

//���ʱ�־����
int visited[MaxVertexNum];

//-------------------------------------the part of base operation function------------------------------------
//���嶥�����������
typedef struct Vertextype
{
	char name[MAXSIZE];
	char information[MAXSIZE];
	char buildings[MAXSIZE];
}Vertextype;


//��ͨ������������
typedef struct vehicle
{
	char name[MAXSIZE];
	int speed;
}vehicle;

//������Ӿ���
typedef struct MGraph
{
	Vertextype Vex[MaxVertexNum];  // �����
	int Edge[3][3];   // �ڽӾ���
	int vexnum, arcnum;  // ͼ��ǰ�Ķ������ͻ���
}MGraph;

// ջ
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
��ջ�Ľڵ�Ķ���
*/

// ջ��ʼ��
void Init_SeqStack(SqStack** s)
{
	// ����һ��ռ䣬�����ÿռ�ĵ�ַ����s
	*s = (SqStack*)malloc(sizeof(SqStack));
	(*s)->top = -1;
}

// ��ջΪ��
int Empty_SeqStack(SqStack* s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

// ��ջ
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

// ��ջ
void Pop_SeqStack(SqStack* s, int* x)
{
	if (s->top == -1)
		printf("ջΪ��!\n");
	else
	{
		*x = s->data[s->top];
		s->top--;
	}
}

// ȡջ��Ԫ��
void Top_SeqStack(SqStack* s, int* x)
{
	if (s->top == -1)
		printf("ջΪ��!\n");
	else
	{
		*x = s->data[s->top];
		printf("��ջ�ɹ���\n");
	}
}
// ���
void Output_SeqStack(SqStack* s)
{
	SqStack* w;
	int i;
	printf("ջ�е�Ԫ���У�");
	for (i = s->top; i >= 0; i--)
		printf("%d ", s->data[i]);
	printf("\n");
}

// ��ѯ����λ��
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

// ��ȡv �ĵ�һ����Ӷ������ţ���������G��û����Ӷ��㣬�򷵻�-1
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

//vΪͼG�е�ĳ�����㣬w ��v����Ӷ��㣬����v�ģ������w����һ����Ӷ�������
int NextAdjVex(MGraph G, Vertextype v, Vertextype w)
{
	// ��w��v�����һ���ڽӶ���,�򷵻�-1
	int i, j = 0, k1, k2;
	k1 = LocateVex(G, v);  // k1Ϊ����v��ͼG�е����
	k2 = LocateVex(G, w);  // k2Ϊ����w��ͼG�е����

	for (i = k2; i < G.vexnum; i++)
	{
		if (G.Edge[k1][i] != j || G.Edge[k1][i] != INF) {
			return i;
		}
	}
	return -1;
}

// ����v��ֵ
// ��ʼ����: ͼG���ڣ�v��G��ĳ���������š��������: ����v��ֵ
Vertextype GetVex(MGraph G, int v)
{
	if (v >= G.vexnum || v < 0)
		exit(1);
	return G.Vex[v];
}

//�洢��ӹ�ϵ
void create_Graph(MGraph* G, Vertextype pointData[], int edgeData[][3])
{
	int numV = 0, numE = 0;

	int i, j;
	int start, end;  // �ߵ��������յ���� //
	int w;  // ���ϵ�Ȩֵ
	G->vexnum = numV;
	G->arcnum = numE;

	printf_s("\n");

	//ͼ�ĳ�ʼ��
	//���������е�ÿ��Ԫ��
	for (i = 0; i < G->vexnum; j++)  // vexnum �������
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

	//������Ϣ���붥���
	for (i = 0; i < G->vexnum; i++)
	{
		G->Vex[i] = pointData[i];
	}
	printf_s("\n");

	//��������ͼ�ߵ���Ϣ

	for (i = 0; i < G->arcnum; i++)
	{
		for (j = 0; j < G->arcnum; j++)
		{
			G->Edge[i][j] = edgeData[i][j];
		}
	}
}

//���ʽڵ���Ϣ����
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

//��һ������

//DFS
// �ӵ�v����������ݹ��������ȱ���ͼG���㷨7.5
void DFS(MGraph* G, int v, int visited[])
{
	int w;
	visitFunc(G, v);
	visited[v] = 1;
	for (w = FirstAdjVex(*G, G->Vex[v]); w >= 0; w = NextAdjVex(*G, G->Vex[v], G->Vex[w]))
	{
		if (!visited[w])
		{
			DFS(G, w, visited);  // ����δ���ʵ���Ӷ����ҵݹ����dfs
		}
	}
}

//DFS��������ͼ
void DFStraveler(MGraph G, int x)
{
	int w, i;
	// visited ��ȫ��δ����
	for (i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
	}
	//dfs���ʵ����岿��
	for (i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			DFS(&G, i, visited);
		}
	}
	printf_s("\n");
}

//BFS�㷨
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
			j = queue[front++];  // �������Ѿ��е�Ԫ�س���

			for (k = FirstAdjVex(G, GetVex(G, j)); k >= 0; k = NextAdjVex(G, GetVex(G, j), GetVex(G, k)))  // ���ʳ���Ԫ�ص����еĽ��
			{
				visited[k] = 1;  // ���ʱ��
				visitFunc(&G, k);  //����
				queue[rear++] = k;  // ���
			}
		}
	}
	printf_s("\n");
}

// �����·��֮�Ͻ�˹�����㷨
// v0 ��ʼ����Ҳ���Ǽ���vs��������������·��
/*
prev -- ǰ���������顣
����prev[i]��ֵ��"����vs"��"����i"�����·����������ȫ�������У�λ��"����i"֮ǰ���Ǹ����㡣
*/
// dist -- �������顣����dist[i]��"����vs"��"����i"�����·���ĳ��ȡ�
void dijkstra(MGraph G, int v0, int prev[], int dist[])
{
	int i, j, k = 0;
	int min;
	int tmp;
	int visited[MAXSIZE];  // ����ѷ�������

	// ��ʼ��
	// ʹ��dist�д������ж����Ȩֵ
	for (i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
		prev[i] = 0;
		dist[i] = G.Edge[v0][i];  // dist[]���ڴ洢���·��ֵ
	}

	visited[v0] = 1;  // ����ʼ����������Ϊ�Ѿ�����
	dist[v0] = 0;  // ����ʼ�㵽����ľ�������Ϊ0

	// ����G.vexnum-1 �Σ�ÿ���ҳ�һ����������·��ֵ
	// �򵥵�˵�����ѭ�������þ�����ͨ�Ľ����������̵�
	for (i = 1; i < G.vexnum; i++)
	{
		// Ѱ�ҵ�ǰ����С·��
		// Ҳ���ǣ���δ��ȡ���·���Ķ����У��ҵ�vs����Ķ���k
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
	// ���ˣ��������Ѿ��ҵ�����v0��ͨ�Ľ������̵ľ�����Ǹ��ˣ�
	// ��kΪĿǰ��֪�����·��
	visited[k] = -1;

	// ������ǰ�����·����ǰ�����㣬Ҳ���ǵ��Ѿ�����δ��ȡ���·����������·����ǰ������
	for (j = 0; j < G.vexnum; j++)
	{
		tmp = (G.Edge[k][j] == INF ? INF : (min + G.Edge[k][j]));  // ��ֹԽ��
		if (visited[j] == 0 && (tmp < dist[j]))
		{
			dist[j] = tmp;
			prev[j] = k;
		}
	}

	// ��ӡ���ս��
	printf_s("dijkstra(%c):\n", (char)(G.Vex[v0]).name);
	for (i = 0; i < G.vexnum; i++)
	{
		printf_s("shortest(%c, %c) = %d\n", (char)(G.Vex[v0].name), (char)(G.Vex[i].name), dist[i]);
	}
}


//-----------------------------the functional function ----------------------------------
// ��ɫ���ú���
/*
color table
0 = ��ɫ       8 = ��ɫ
1 = ��ɫ       9 = ����ɫ
2 = ��ɫ       A = ����ɫ
3 = ǳ��ɫ     B = ��ǳ��ɫ
4 = ��ɫ       C = ����ɫ
5 = ��ɫ       D = ����ɫ
6 = ��ɫ       E = ����ɫ
7 = ��ɫ       F = ����ɫ

*/
void color(short x)
{
	if (x >= 0 && x <= 15)//������0-15�ķ�Χ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ
	else//Ĭ�ϵ���ɫ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//��ʼ����
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
	system("cls");			//����
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
	system("cls");			//����
	printf_s("Please input the name of start:\n");
	gets(start);
	printf_s("Please input the name of end:\n");
	gets(end);
}

void filereadNUM(int mapdata[3][3])
{
	int i, j;
	int k = 0;
	int count = 0;  //ͳ���ļ����ַ�����
	int sum_row;  //ͳ���ļ����ַ�����
	int flag = 0;  //������ʱ���ļ����ݱ���
	FILE* fp;    //�ļ�ָ��
	FILE* fp1;
	fp = fopen("datanumber.txt", "r");   //���ļ���ֻ����argv[1]�����������������ļ����ƣ�������.exe����ʱ����ĵڶ�������
	fp1 = fopen("datanumber.txt", "r");   //�ٴδ��ļ�������һ�δ��ļ�����ͳ���ļ��������������ݵĸ��������ڽ��ļ����ݱ��浽ָ��������
	// fp2 = fopen("test1.txt", "w");   //���ļ���ֻд�����ڽ������������±��浽��һ���ļ���
	if (fp == NULL)    //���ļ�ʧ��
	{
		printf("File cannot open! ");
		//exit;  
		return 0;
	}
	i = 0;
	while (!feof(fp))  //���ļ���ֱ���ļ�ĩβ
	{
		fscanf(fp, "%d %d %d", &mapdata[i][0], &mapdata[i][1], &mapdata[i][2]);
		i++;
		count++;
	}
	k = i;
	sum_row = count + 1; //�����ļ����һ�У���Ϊ�ļ��ܵ�����
	printf("�ļ�����Ϊ��%d", sum_row);  //ͳ���ļ���������Ϊÿ��ֻ��һ���������Լ�ͳ���ļ����ж��ٸ���
	printf("\n");

	printf("�ļ�����Ϊ��\n");


	for (i = 0; i < k; i++)  //ѭ����ӡ���浽ָ�������е�����
	{
		for (j = 0; j < k; j++)
		{
			printf("%d\t", mapdata[i][j]);  //��ӡ
		}
		printf("\n");

	}
	fclose(fp);  //�ر��ļ����ͷ�ָ���ļ���ָ��
	fclose(fp1);  //�ر��ļ����ͷ�ָ���ļ���ָ��


}

void filereadCHR(Vertextype data[])
{
	int i, j;
	FILE* fp;
	fp = fopen("imformation", 'r');
	if (fp == NULL)    //���ļ�ʧ��
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

	//�洢����
	Vertextype points[100];
	
		/*
		=
	{
		{ "ѧ��¥","������Ҫ��ѧ¥","ѧ��¥" },
		{ "�ĺ���","ͨ�����ֱ��ݣ���У������������","���ֱ���" },
		{ "������","������Ҫ���ڣ�ͨ�����������򳡡�����ס����","���� ס����"}
	};
		*/
		
	filereadNUM(mapdata);

	//���ݴ洢ͼ�ĳ�ʼ��
	create_Graph(campus, points, edgedata);

	StartMenu(*campus);

	free(campus);
	return 0;
}