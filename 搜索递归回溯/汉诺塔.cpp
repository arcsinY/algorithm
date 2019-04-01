#include <stdio.h>
void hanoi(int n, char a, char b, char c);
int main(void)
{
	int n;
	printf("盘子个数:");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

void hanoi(int n, char a, char b, char c)
{
	if (n == 0)
		return;
	hanoi(n - 1, a, c, b);
	printf("将盘子%d从%c柱移到%c柱\n", n, a, c);
	hanoi(n - 1, c, a, b);
}