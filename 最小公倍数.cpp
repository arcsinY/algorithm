#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", a*b / gcd(a, b));
	}
	return 0;
}
