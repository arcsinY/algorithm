#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct Node   //树的链式结构
{
	char data;
	struct Node* lchild;
	struct Node* rchild;
}Node;

void Build(Node* &T)  //建立二叉树
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		T = NULL;
	else
	{
		T = (Node*)malloc(sizeof(Node));
		T->data = ch;
		Build(T->lchild);
		Build(T->rchild);
	}
}

void preOrder(Node* T)  //前序遍历
{
	if (T != NULL)
	{
		printf("%c", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(Node* T)   //中序遍历
{
	if (T != NULL)
	{
		inOrder(T->lchild);
		printf("%c", T->data);
		inOrder(T->rchild);
	}
}

void postOrder(Node* T)   //后序遍历
{
	if (T != NULL)
	{
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c", T->data);
	}
}

void levelOrder(Node* T)
{
	queue<Node*> q;
	q.push(T);   //根结点进队列
	while (q.empty() == false)
	{
		Node* t = q.front();
		q.pop();
		if (t == NULL)   //空的直接出队
			continue;
		printf("%c", t->data);  //不空的指针输出数据，孩子结点入队
		q.push(t->lchild);
		q.push(t->rchild);
	}
}
int main()
{
	Node* T;
	Build(T);
	preOrder(T);
	printf("\n");
	inOrder(T);
	printf("\n");
	postOrder(T);
	printf("\n");
	levelOrder(T);
	printf("\n");
	return 0;
}
