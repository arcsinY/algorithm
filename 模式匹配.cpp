#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Input(char* str1, char* str2, int* pos);     //����������ģʽ����ƥ��λ�õĺ���
void Index_BF(char* str1, char* str2, int pos);   //���ص�ƥ���㷨
void Index_Next(char* str1, char* str2, int pos);      //KMP�㷨
void Index_NextVal(char* str1, char* str2, int pos);    //KMP�Ľ��㷨(NextVal[])
void Output(char* str);    //���������ģʽ��
void getNext(char *str1, int* &next);   //����next�����ֵ
void getNext_val(char* str2, int* &nextval);

void main()
{
	int choice;
	char str1[1000];
	char str2[100];
	int pos;
	while(1)
	{
		printf("��ѡ���ܣ�\n");
		printf("1.�����������Ӵ���ƥ����ʼλ��\n");
		printf("2.���ص�ģʽƥ���㷨\n");
		printf("3.KMP�Ľ��㷨(Next[])\n");
		printf("4.KMP�Ľ��㷨(NextVal[])\n");
		printf("0.�˳�����ϵͳ\n");
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
			printf("�������ִ���\n");
		}
	}
}


void Input(char* str1, char* str2, int* pos)
{
	int i = 1;int j = 1;
	char ch;
	printf("������������");
	ch = getchar();
	while((ch = getchar()) != '\n')
	{
		str1[i++] = ch;
	}
	str1[i] = '\0';
	printf("\n������ģʽ��:");
	while((ch = getchar()) != '\n')
	{
		str2[j++] = ch;
	}
	str2[j] = '\0';
	str1[0] = strlen(str1) - 1;
	str2[0] = strlen(str2) - 1;
	printf("\n�����뿪ʼƥ���λ��:");
	scanf("%d", pos);
}


void Index_BF(char* str1, char* str2, int pos)
{
	int sum = 1,count = 0;    //sum��ʾƥ����������count��ʾ�Ƚϴ���
	int i = pos; int j = 1;
	printf("%c", str1[9]);
	while(i<=str1[0] && j<=str2[0])
	{
		printf("\n��%d��ƥ��:\n", sum);
		Output(str1);
		printf("\n");
		for(int m = 1;m<=i-1;++m)     //���ݵ�ǰƥ��λ�������ո�
			printf(" ");
		Output(str2);
		printf("\n");
		while(str1[i] == str2[j] && i<=str1[0] && j<=str2[0])     //�����ַ���ͬ���Ƚϴ���+1
		{
			++i;
			++j;
			++count;
		}
		if (j > str2[0])
		{
			printf("ƥ��������%d\t", sum);
			printf("�Ƚϴ�����%d\t", count);
			printf("ƥ��λ�ã�%d\t", i - str2[0]);
		}
		else     //�����ַ���ͬ���Ƚϴ���+1��ƥ������+1
		{
			i = i-j+2;
			j = 1;
			++sum; ++count;
		}
	}
	if(i>str1[0]&&j<=str2[0])
		printf("ƥ��ʧ��");
	printf("\n\n\n");
}


void Index_Next(char* str1, char* str2, int pos)
{
	int sum = 1, count = 0;
	int *next;
	getNext(str2, next);
	printf("j\t");     //���next����
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
		printf("\n��%d��ƥ��:\n", sum);
		Output(str1);
		printf("\n");
		for (int m = 1; m <= i - j; ++m)    
			printf(" ");
		Output(str2);
		printf("\n");
		while (j == 0 || str1[i] == str2[j] && i<=str1[0] && j<=str2[0])
		{
			if (j != 0)    //j������0ʱ��˵��������ģʽ����ȣ����ӱȽϴ���
			{	
				++count;
				++i;++j;
			}
			else    //j����0ʱ��ֱ�ӿ�ʼ�Ƚϣ������Ӵ���
			{
				++i;++j;
				continue;
			}
		}
		if (j > str2[0])
		{
			printf("ƥ��������%d\t", sum);
			printf("�Ƚϴ�����%d\t", count);
			printf("ƥ��λ�ã�%d\t", i - str2[0]);
		}
		else
		{
			++sum; ++count;
			j = next[j];
		}
	}
	if (i>str1[0] && j <= str2[0])
		printf("ƥ��ʧ��");
	printf("\n\n\n");
}


void Index_NextVal(char* str1, char* str2, int pos)
{
	int sum = 1, count = 0;
	int* nextval;
	getNext_val(str2, nextval);
	printf("j\t   ");     //���nextval����
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
		printf("\n��%d��ƥ��:\n", sum);
		Output(str1);
		printf("\n");
		for (int m = 1; m <= i - j; ++m)    
			printf(" ");
		Output(str2);
		printf("\n");
		while (j == 0 || str1[i] == str2[j] && i<=str1[0] && j<=str2[0])
		{
			if (j != 0)    //j������0ʱ��˵��������ģʽ����ȣ����ӱȽϴ���
			{	
				++count;
				++i;++j;
			}
			else    //j����0ʱ��ֱ�ӿ�ʼ�Ƚϣ������Ӵ���
			{
				++i;++j;
				continue;
			}
		}
		if (j > str2[0])
		{
			printf("ƥ��������%d\t", sum);
			printf("�Ƚϴ�����%d\t", count);
			printf("ƥ��λ�ã�%d\t", i - str2[0]);
		}
		else
		{
			++sum; ++count;
			j = nextval[j];
		}
	}
	if (i>str1[0] && j <= str2[0])
		printf("ƥ��ʧ��");
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
	next = (int*)malloc((str1[0]+1) * sizeof(int));   //����next����ĳ���
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
