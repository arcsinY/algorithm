#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct Node   //������ʽ�ṹ
{
	char data;
	struct Node* lchild;
	struct Node* rchild;
}Node;

void Build(Node* &T)  //����������
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

void preOrder(Node* T)  //ǰ�����
{
	if (T != NULL)
	{
		printf("%c", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(Node* T)   //�������
{
	if (T != NULL)
	{
		inOrder(T->lchild);
		printf("%c", T->data);
		inOrder(T->rchild);
	}
}

void postOrder(Node* T)   //�������
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
	q.push(T);   //����������
	while (q.empty() == false)
	{
		Node* t = q.front();
		q.pop();
		if (t == NULL)   //�յ�ֱ�ӳ���
			continue;
		printf("%c", t->data);  //���յ�ָ��������ݣ����ӽ�����
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
