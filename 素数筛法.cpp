#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int p[100000];
bool mark[100000];   //Ϊ1�Ƿ�����
int primeSize;   //���������������±꣩
void prime()  //������
{
	memset(mark, 0, sizeof(mark));
	for (int i = 2; i <= 100000; i++) 
	{
		if (mark[i] == true)    //���i�Ѿ����������ˣ�����һ��
			continue;       
		p[primeSize++] = i;        
		for (unsigned long long int j = i*i; j<100000; j += i)//�������������б��������Ϊ������  
			mark[j] = true;       
	}
}

int main()
{
	prime();
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", p[n - 1]);
	}
	return 0;
}
