#include <stdio.h>
#include <string.h>


int main()
{
	int n, m;   //n����תΪm����
	char s[40];    //���ַ�����������Ϊ������ĸ
	while (scanf("%d %s %d", &n, s, &m) != EOF)
	{
		long t = 0;
		for (int i = 0; i < strlen(s); ++i)   //�ַ���תΪʮ������t
		{
			if (s[i] >= 'a' && s[i] <= 'f')
				t = t*n + (s[i] - 'a' + 10);  //�����ĸ���������
			else if (s[i] >= 'A' && s[i] <= 'F')
				t = t*n + (s[i] - 'A' + 10);
			else
				t = t*n + (s[i] - '0');
		}
		char res[40]; int i = 0;   //res����
		do
		{  //���϶�mȡ�������ת����ÿһλ��ֵ
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
