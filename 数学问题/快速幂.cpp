#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <math.h>
//º∆À„a^b
int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		int res = 1;
		while (b)
		{
			if (b % 2 == 1)
				res *= a;
			b /= 2;
			a *= a;
		}
		printf("%d\n", res);
	}
	return 0;
}

