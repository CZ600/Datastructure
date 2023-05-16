#include<stdio.h>
#include<stdlib.h>


// 定义一个二叉树
typedef struct BTNode
{
	char data;
	struct BTNode* lchild, * rchild;
}BTNode;

typedef struct QNode  //队列节点的定义
{
	BTNode data;
	struct QNode* Next;
}QNode;

typedef struct  // 链队列的定义
{
	QNode* front;  // 定义队头指针
	QNode* rear;  // 定义队尾指针
}LiQNode;  //定义链队列LiQNode

//初始化队列
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

//入队列
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

//判断队列是否为空
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

//遍历二叉树(层次遍历）
void LevelOrder(BTNode *T) 
{
	LiQNode Q;  //定义新的的队列存储书树中的节点
	InitQueue(&Q);	//初始化队列
	BTNode *p;
	EnQueue(&Q, T);	//将根节点入队
	while (!IsEmpty(Q)) {	//队列不空则循环
		DeQueue(&Q, p);	//队头结点出队
		visit(p);	//访问出队结点
		if (p->lchild != NULL) {
			EnQueue(&Q, p->lchild);	//左子树不空，则左子树根节点入队
		}
		if (p->rchild != NULL) {
			EnQueue(&Q, p->rchild);	//右子树不空，则右子树根节点入队
		}
	}
}

//求树的深度
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
			//得到这一层的node个数
			int levelNodeSize = queue.size();
			//取完这一层，并下一层的node也就全部放进去
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