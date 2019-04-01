#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Input(char* str1, char* str2, int* pos);     //输入主串、模式串、匹配位置的函数
void Index_BF(char* str1, char* str2, int pos);   //朴素的匹配算法
void Index_Next(char* str1, char* str2, int pos);      //KMP算法
void Index_NextVal(char* str1, char* str2, int pos);    //KMP改进算法(NextVal[])
void Output(char* str);    //输出主串或模式串
void getNext(char *str1, int* &next);   //计算next数组的值
void getNext_val(char* str2, int* &nextval);

void main()
{
	int choice;
	char str1[1000];
	char str2[100];
	int pos;
	while(1)
	{
		printf("请选择功能：\n");
		printf("1.输入主串、子串和匹配起始位置\n");
		printf("2.朴素的模式匹配算法\n");
		printf("3.KMP改进算法(Next[])\n");
		printf("4.KMP改进算法(NextVal[])\n");
		printf("0.退出管理系统\n");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			Input(str1, str2, &pos);
			break;
		case 2:
			Index_BF(str1, str2, pos);
			break;
		case 3:
			Index_Next(str1, str2, pos);
			break;
		case 4:
			Index_NextVal(str1, str2, pos);
			break;
		case 0:
			return;
		default:
			printf("输入数字错误\n");
		}
	}
}


void Input(char* str1, char* str2, int* pos)
{
	int i = 1;int j = 1;
	char ch;
	printf("请输入主串：");
	ch = getchar();
	while((ch = getchar()) != '\n')
	{
		str1[i++] = ch;
	}
	str1[i] = '\0';
	printf("\n请输入模式串:");
	while((ch = getchar()) != '\n')
	{
		str2[j++] = ch;
	}
	str2[j] = '\0';
	str1[0] = strlen(str1) - 1;
	str2[0] = strlen(str2) - 1;
	printf("\n请输入开始匹配的位置:");
	scanf("%d", pos);
}


void Index_BF(char* str1, char* str2, int pos)
{
	int sum = 1,count = 0;    //sum表示匹配总趟数，count表示比较次数
	int i = pos; int j = 1;
	printf("%c", str1[9]);
	while(i<=str1[0] && j<=str2[0])
	{
		printf("\n第%d次匹配:\n", sum);
		Output(str1);
		printf("\n");
		for(int m = 1;m<=i-1;++m)     //根据当前匹配位置留出空格
			printf(" ");
		Output(str2);
		printf("\n");
		while(str1[i] == str2[j] && i<=str1[0] && j<=str2[0])     //两个字符相同，比较次数+1
		{
			++i;
			++j;
			++count;
		}
		if (j > str2[0])
		{
			printf("匹配趟数：%d\t", sum);
			printf("比较次数：%d\t", count);
			printf("匹配位置：%d\t", i - str2[0]);
		}
		else     //俩个字符不同，比较次数+1，匹配趟数+1
		{
			i = i-j+2;
			j = 1;
			++sum; ++count;
		}
	}
	if(i>str1[0]&&j<=str2[0])
		printf("匹配失败");
	printf("\n\n\n");
}


void Index_Next(char* str1, char* str2, int pos)
{
	int sum = 1, count = 0;
	int *next;
	getNext(str2, next);
	printf("j\t");     //输出next数组
	for (int m = 1; m <= str2[0]; ++m)
	{
		printf("%d ", m);
	}
	printf("\nnext[j] ");
	for (int n = 1; n <= str2[0]; ++n)
	{
		printf("%d ", next[n]);
	}
	printf("\n");
	int i = pos, j = 1;
	while (i <= str1[0] && j <= str2[0])
	{
		printf("\n第%d次匹配:\n", sum);
		Output(str1);
		printf("\n");
		for (int m = 1; m <= i - j; ++m)    
			printf(" ");
		Output(str2);
		printf("\n");
		while (j == 0 || str1[i] == str2[j] && i<=str1[0] && j<=str2[0])
		{
			if (j != 0)    //j不等于0时，说明主串与模式串相等，增加比较次数
			{	
				++count;
				++i;++j;
			}
			else    //j等于0时，直接开始比较，不增加次数
			{
				++i;++j;
				continue;
			}
		}
		if (j > str2[0])
		{
			printf("匹配趟数：%d\t", sum);
			printf("比较次数：%d\t", count);
			printf("匹配位置：%d\t", i - str2[0]);
		}
		else
		{
			++sum; ++count;
			j = next[j];
		}
	}
	if (i>str1[0] && j <= str2[0])
		printf("匹配失败");
	printf("\n\n\n");
}


void Index_NextVal(char* str1, char* str2, int pos)
{
	int sum = 1, count = 0;
	int* nextval;
	getNext_val(str2, nextval);
	printf("j\t   ");     //输出nextval数组
	for (int m = 1; m <= str2[0]; ++m)
	{
		printf("%d ", m);
	}
	printf("\nnextval[j] ");
	for (int n = 1; n <= str2[0]; ++n)
	{
		printf("%d ", nextval[n]);
	}
	printf("\n");
	int i = pos, j = 1;
	while (i <= str1[0] && j <= str2[0])
	{
		printf("\n第%d次匹配:\n", sum);
		Output(str1);
		printf("\n");
		for (int m = 1; m <= i - j; ++m)    
			printf(" ");
		Output(str2);
		printf("\n");
		while (j == 0 || str1[i] == str2[j] && i<=str1[0] && j<=str2[0])
		{
			if (j != 0)    //j不等于0时，说明主串与模式串相等，增加比较次数
			{	
				++count;
				++i;++j;
			}
			else    //j等于0时，直接开始比较，不增加次数
			{
				++i;++j;
				continue;
			}
		}
		if (j > str2[0])
		{
			printf("匹配趟数：%d\t", sum);
			printf("比较次数：%d\t", count);
			printf("匹配位置：%d\t", i - str2[0]);
		}
		else
		{
			++sum; ++count;
			j = nextval[j];
		}
	}
	if (i>str1[0] && j <= str2[0])
		printf("匹配失败");
	printf("\n\n\n");
}


void Output(char* str)
{
	int i = 1;
	while(str[i] != '\0')
	{
		printf("%c", str[i++]);
	}
}

void getNext(char * str1, int* &next)
{
	int i = 1, j = 0;
	next = (int*)malloc((str1[0]+1) * sizeof(int));   //计算next数组的长度
	next[1] = 0;
	while (i < str1[0])
	{
		if (j == 0 || str1[i] == str1[j])
		{
			++i; ++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

void getNext_val(char* str2, int* &nextval)
{
	int i = 1;
	int j = 0;
	nextval = (int*)malloc((str2[0]+1) * sizeof(int));
	nextval[1] = 0;
	while(i<str2[0])
	{
		if(j == 0 || str2[i] == str2[j])
		{
			++i;++j;
			if(str2[i] != str2[j])
			{
				nextval[i] = j;
			}
			else 
				nextval[i] = nextval[j];
		}
		else 
			j = nextval[j];
	}
}
