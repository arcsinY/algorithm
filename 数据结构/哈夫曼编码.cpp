#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char letter;
	int weight;
	int parent, lchild, rchild;   //˫�ף����Һ����������е�λ��
}HTnode, *HuffmanTree;

void HuffmanCoding(HuffmanTree &HT, char** &HC, int n);  //���ɹ�������
void select(HuffmanTree HT, int n, int* s1, int* s2);    //������HT[1~n]��ѡ��Ȩֵ����������
void makeCode(char* sentence, char** HC, char* code);   //�����ӷ���ɹ��������룬����code�ַ�����
void translateCode(char* code, int n, HuffmanTree HT);  //��һ������code����ɾ���

char ch[28];
char sentence[28] = "This program is my favorite";
int weight[27] = { 186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1 };
char code[300];   //�洢һ�仰�ı���

void main()
{
	ch[1] = ' ';
	char let = 'a';
	for (int i = 2; i <= 27; ++i)   //Ϊ��ĸ���鸳ֵ
	{
		ch[i] = let;
		++let;
	}
	HuffmanTree HT;   //������洢��������
	char** HC;   //ָ���ַ�ָ���ָ�룬�洢����
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
	int m = 2 * n - 1;    //�ܽ�����=���Ƚ����+Ҷ����=n+1+n=2n+1
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTnode));   //Ϊ�������������ռ�
	for (int i = 1;i<=n;++i)    //ǰn��Ԫ������ĸ��Ҷ�ӽ�㣩
	{
		HT[i].letter = ch[i];   //��ĸ��ֵ
		HT[i].weight = weight[i-1];   //Ȩֵ
		HT[i].lchild = HT[i].rchild = HT[i].parent = 0;   //���Һ��ӣ�˫�׳�ʼ��Ϊ0
	}
	for (int i = n + 1; i <= m; ++i)   //֮���Ԫ���Ƕ��Ƚ�㣬��ʼ��Ϊ0
	{
		HT[i].lchild = HT[i].rchild = HT[i].parent = HT[i].weight = 0;
	}
	for (int i = n + 1; i <= m; ++i)   //��ʼ���ɶ��Ƚ��
	{
		int s1, s2;
		select(HT, i - 1, &s1, &s2);  //ѡ�����н����˫��Ϊ0����С��������Ϊ�������ɳ�˫�׽��
		HT[s1].parent = HT[s2].parent = i;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
	}
	HC = (char**)malloc((n + 1) * sizeof(char*));  //ΪHC����n+1���ַ�ָ��
	char* cd = (char*)malloc(n * sizeof(char));   //����һ����ʱ�洢����Ŀռ�
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; ++i)
	{
		int start = n - 1;
		for (int c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{     //��Ҷ�ӽ�㿪ʼ����ڵ�������õ����������롣c�ǵ�ǰ����±꣬f��˫�׽���±�
			if (HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));    //ΪHC��ÿ���ַ�ָ�������ʵĿռ�
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
	for (int i = 1; i <= 27; ++i)  //���ÿ���ַ��ı���
	{
		printf("%c  ", HT[i].letter);
		printf("%s\n", HC[i]);
	}
}

void select(HuffmanTree HT, int n, int * s1, int * s2)
{
	int min, sec;   //minΪȨֵ��СԪ�ص��±�secΪ�ڶ�С��
	int i;
	for (i = 1; i <= n; ++i)    //�ҵ�����˫��Ϊ0�Ľ����ʱ��Ϊmin��sec
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
		if (HT[i].weight < HT[min].weight && HT[i].parent == 0)//�ҵ�Ȩֵ��HT[min]С����˫��Ϊ0��Ԫ�أ���¼�±�
		{
			sec = min;
			min = i;
		}
		else if (HT[i].weight > HT[min].weight && HT[i].weight < HT[sec].weight && HT[i].parent == 0)//
		{   //�ҵ�Ȩֵ��HT[min]�󵫱�HT[sec]�����˫��Ϊ0��Ԫ�أ���Ϊsec
			sec = i;
		}
	}
	*s1 = min;
	*s2 = sec;
}

void makeCode(char* sentence, char** HC, char* code)
{
	printf("Ҫ����ľ����ǣ�%s\n����Ϊ��", sentence);
	for (int j = 0; j<strlen(sentence); ++j)
	{
		if (sentence[j] == ' ')
			strcat(code, HC[1]);
		else
		{
			int pos = (int)tolower(sentence[j]) - 95;    //������ĸ��HT�е�λ�ã�a��2
			strcat(code, HC[pos]);  //�����Ӧλ�õĹ���������
		}
	}
	printf("%s\n", code);
}

void translateCode(char* code, int n, HuffmanTree HT)
{   //�Ӹ���㿪ʼ����������Ϊ0�����ߣ�����Ϊ1�����ߣ�ֱ���ߵ�Ҷ�ӽ��
	int tag = 0;  //��־����ĸ��д�ı�����0��ʾ�������ĸ����Ҫ��д
	printf("����ɵľ����ǣ�");
	int i = 0; int root, letter;   
	for (int j = 1; j < 2 * n; ++j)    //�ҵ����ڵ�,�±�Ϊroot
	{
		if (HT[j].parent == 0)
		{
			root = j;
		}
	}
	while (code[i] != '\0')
	{
		letter = root;
		while (HT[letter].lchild != 0 && HT[letter].rchild != 0)  //û�ߵ�Ҷ�ӽ���������
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