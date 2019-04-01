#include <stdio.h>
void hanoi(int n, char a, char b, char c);
int main(void)
{
	int n;
	printf("���Ӹ���:");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

void hanoi(int n, char a, char b, char c)
{
	if (n == 0)
		return;
	hanoi(n - 1, a, c, b);
	printf("������%d��%c���Ƶ�%c��\n", n, a, c);
	hanoi(n - 1, c, a, b);
}