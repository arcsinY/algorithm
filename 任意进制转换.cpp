#include <stdio.h>
#include <string.h>


int main()
{
	int n, m;   //n进制转为m进制
	char s[40];    //用字符串存数，因为会有字母
	while (scanf("%d %s %d", &n, s, &m) != EOF)
	{
		long t = 0;
		for (int i = 0; i < strlen(s); ++i)   //字符串转为十进制数t
		{
			if (s[i] >= 'a' && s[i] <= 'f')
				t = t*n + (s[i] - 'a' + 10);  //算出字母代表的数字
			else if (s[i] >= 'A' && s[i] <= 'F')
				t = t*n + (s[i] - 'A' + 10);
			else
				t = t*n + (s[i] - '0');
		}
		char res[40]; int i = 0;   //res存结果
		do
		{  //不断对m取余数求出转换后每一位的值
			if (t%m >= 10)
				res[i++] = t % m - 10 + 'A';
			else
				res[i++] = t % m + '0';
			t /= m;
		} while (t);
		for (int j = i-1; j >= 0; --j)
		{
			printf("%c", res[j]);
		}
		printf("\n");
	}
	return 0;
}
