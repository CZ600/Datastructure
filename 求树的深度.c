#include<stdio.h>
#include<stdlib.h>


// ����һ��������
typedef struct BTNode
{
	char data;
	struct BTNode* lchild, * rchild;
}BTNode;

typedef struct QNode  //���нڵ�Ķ���
{
	BTNode data;
	struct QNode* Next;
}QNode;

typedef struct  // �����еĶ���
{
	QNode* front;  // �����ͷָ��
	QNode* rear;  // �����βָ��
}LiQNode;  //����������LiQNode

//��ʼ������
int InitQueue(LiQNode* q)
{
	q->front = q->rear = (QNode*)malloc(sizeof(QNode));
	if (!q->front)
	{
		return -1;
	}
	q->front->Next = NULL;
	return 1;
}

//�����
int EnQueue(LiQNode* q, char a)
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (!p)
	{
		return -1;
	}
	p->data = a;
	p->Next = q->rear->Next;
	q->rear->Next = p;
	q->rear = p;
	return 1;
	
}

//�ж϶����Ƿ�Ϊ��
int IsEmpty(LiQNode q)
{
	if (q.front == q.rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//����������(��α�����
void LevelOrder(BTNode *T) 
{
	LiQNode Q;  //�����µĵĶ��д洢�����еĽڵ�
	InitQueue(&Q);	//��ʼ������
	BTNode *p;
	EnQueue(&Q, T);	//�����ڵ����
	while (!IsEmpty(Q)) {	//���в�����ѭ��
		DeQueue(&Q, p);	//��ͷ������
		visit(p);	//���ʳ��ӽ��
		if (p->lchild != NULL) {
			EnQueue(&Q, p->lchild);	//���������գ������������ڵ����
		}
		if (p->rchild != NULL) {
			EnQueue(&Q, p->rchild);	//���������գ������������ڵ����
		}
	}
}

//���������
int getTreeDeepth(BTNode bt, int a)
{
	
}

/*
public static int maxDepth2(TreeNode root) {
		if (root == null) return 0;

		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		int depth = 0;
		while (!queue.isEmpty()){
			//�õ���һ���node����
			int levelNodeSize = queue.size();
			//ȡ����һ�㣬����һ���nodeҲ��ȫ���Ž�ȥ
			while (levelNodeSize > 0){
				TreeNode node = queue.poll();
				if(node.left != null)
					queue.offer(node.left);
				if(node.right != null){
					queue.offer(node.right);
				}
				levelNodeSize--;
			}
			depth++;
		}
		return depth;

	}
}
*/


int main()
{

}