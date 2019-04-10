#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char letter;
	int weight;
	int parent, lchild, rchild;   //双亲，左右孩子在数组中的位置
}HTnode, *HuffmanTree;

void HuffmanCoding(HuffmanTree &HT, char** &HC, int n);  //生成哈夫曼树
void select(HuffmanTree HT, int n, int* s1, int* s2);    //在数组HT[1~n]中选择权值最大的两个数
void makeCode(char* sentence, char** HC, char* code);   //将句子翻译成哈夫曼编码，存在code字符串中
void translateCode(char* code, int n, HuffmanTree HT);  //将一串编码code翻译成句子

char ch[28];
char sentence[28] = "This program is my favorite";
int weight[27] = { 186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1 };
char code[300];   //存储一句话的编码

void main()
{
	ch[1] = ' ';
	char let = 'a';
	for (int i = 2; i <= 27; ++i)   //为字母数组赋值
	{
		ch[i] = let;
		++let;
	}
	HuffmanTree HT;   //用数组存储哈夫曼树
	char** HC;   //指向字符指针的指针，存储编码
	HuffmanCoding(HT, HC, 27);
	makeCode(sentence, HC, code);
	translateCode(code, 27, HT);
}

void HuffmanCoding(HuffmanTree &HT, char** &HC, int n)
{
	if (n <= 1)
	{
		return;
	}
	int m = 2 * n - 1;    //总结点个数=二度结点数+叶子数=n+1+n=2n+1
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTnode));   //为哈夫曼数组分配空间
	for (int i = 1;i<=n;++i)    //前n个元素是字母（叶子结点）
	{
		HT[i].letter = ch[i];   //字母的值
		HT[i].weight = weight[i-1];   //权值
		HT[i].lchild = HT[i].rchild = HT[i].parent = 0;   //左右孩子，双亲初始化为0
	}
	for (int i = n + 1; i <= m; ++i)   //之后的元素是二度结点，初始化为0
	{
		HT[i].lchild = HT[i].rchild = HT[i].parent = HT[i].weight = 0;
	}
	for (int i = n + 1; i <= m; ++i)   //开始生成二度结点
	{
		int s1, s2;
		select(HT, i - 1, &s1, &s2);  //选择已有结点中双亲为0的最小两个，作为孩子生成出双亲结点
		HT[s1].parent = HT[s2].parent = i;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
	}
	HC = (char**)malloc((n + 1) * sizeof(char*));  //为HC分配n+1个字符指针
	char* cd = (char*)malloc(n * sizeof(char));   //分配一个临时存储编码的空间
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; ++i)
	{
		int start = n - 1;
		for (int c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{     //从叶子结点开始向根节点遍历，得到哈夫曼编码。c是当前结点下标，f是双亲结点下标
			if (HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));    //为HC的每个字符指针分配合适的空间
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
	for (int i = 1; i <= 27; ++i)  //输出每个字符的编码
	{
		printf("%c  ", HT[i].letter);
		printf("%s\n", HC[i]);
	}
}

void select(HuffmanTree HT, int n, int * s1, int * s2)
{
	int min, sec;   //min为权值最小元素的下表，sec为第二小的
	int i;
	for (i = 1; i <= n; ++i)    //找到两个双亲为0的结点暂时设为min和sec
	{
		if (HT[i].parent == 0)
		{
			min = i;
			break;
		}
	}
	for (int j = i + 1; j <= n; ++j)
	{
		if (HT[j].parent == 0)
		{
			sec = j;
			break;
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		if (HT[i].weight < HT[min].weight && HT[i].parent == 0)//找到权值比HT[min]小的且双亲为0的元素，记录下标
		{
			sec = min;
			min = i;
		}
		else if (HT[i].weight > HT[min].weight && HT[i].weight < HT[sec].weight && HT[i].parent == 0)//
		{   //找到权值比HT[min]大但比HT[sec]大的且双亲为0的元素，记为sec
			sec = i;
		}
	}
	*s1 = min;
	*s2 = sec;
}

void makeCode(char* sentence, char** HC, char* code)
{
	printf("要编码的句子是：%s\n编码为：", sentence);
	for (int j = 0; j<strlen(sentence); ++j)
	{
		if (sentence[j] == ' ')
			strcat(code, HC[1]);
		else
		{
			int pos = (int)tolower(sentence[j]) - 95;    //计算字母在HT中的位置，a是2
			strcat(code, HC[pos]);  //输出对应位置的哈夫曼编码
		}
	}
	printf("%s\n", code);
}

void translateCode(char* code, int n, HuffmanTree HT)
{   //从根结点开始，遇到编码为0向左走，编码为1向右走，直到走到叶子结点
	int tag = 0;  //标志首字母大写的变量，0表示输出首字母，需要大写
	printf("翻译成的句子是：");
	int i = 0; int root, letter;   
	for (int j = 1; j < 2 * n; ++j)    //找到根节点,下标为root
	{
		if (HT[j].parent == 0)
		{
			root = j;
		}
	}
	while (code[i] != '\0')
	{
		letter = root;
		while (HT[letter].lchild != 0 && HT[letter].rchild != 0)  //没走到叶子结点则继续走
		{
			if (code[i] == '0')
				letter = HT[letter].lchild;
			else if (code[i] == '1')
				letter = HT[letter].rchild;
			++i;
		}
		if (!tag)
		{
			printf("%c", toupper(HT[letter].letter));
			tag = 1;
		}
		else
			printf("%c", HT[letter].letter);
	}
	printf("\n");
}