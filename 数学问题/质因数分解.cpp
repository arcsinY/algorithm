#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
bool mark[1000];
int prime[1000];
int ind;
int cnt[1000];
void init()
{
	memset(mark, 0, sizeof(mark));
	for (int i = 2; i < 1000; ++i)
	{
		if (mark[i] == true)
			continue;
		prime[ind++] = i;
		for (int j = i*i; j < 1000; j += i)
		{
			mark[j] = true;
		}
	}
}
int main()
{
	init();
	int n;
	int res = 0;
	while (scanf("%d", &n) != EOF)
	{
		res = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < ind; ++i)
		{
			while (n%prime[i] == 0)
			{
				cnt[i]++;
				n /= prime[i];
			}
		}
		if (n != 1)
			res += 1;
		for (int i = 0; i < 1000; ++i)
		{
			res += cnt[i];
		}
		printf("%d\n", res);
	}
	return 0;
}

