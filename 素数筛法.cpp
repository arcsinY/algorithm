#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int p[100000];
bool mark[100000];   //为1是非素数
int primeSize;   //素数个数（数组下标）
void prime()  //找素数
{
	memset(mark, 0, sizeof(mark));
	for (int i = 2; i <= 100000; i++) 
	{
		if (mark[i] == true)    //这个i已经不是素数了，试下一个
			continue;       
		p[primeSize++] = i;        
		for (unsigned long long int j = i*i; j<100000; j += i)//并将该数的所有倍数都标记为非素数  
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
