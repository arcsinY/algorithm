#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <map>
#include <limits.h>
#include <math.h>
using namespace std;
char letter[26][1000];  //ÿ����ĸ��Ӧһ��һλ���飬���ִ�Сд��26����ĸ
int pos[26];   //26�������λ��
void bucketSort(char* str, int len);
int main()
{
	
	return 0;
}

void bucketSort(char* str, int len)
{
	for (int i = 0; i < len; ++i)  //ÿ����ĸ���ڶ�Ӧ��һά������
	{
		if (isupper(str[i]))
			letter[str[i] - 'A'][pos[str[i] - 'A']++] = str[i];
		else
			letter[str[i] - 'a'][pos[str[i] - 'a']++] = str[i];
	}
	int j = 0, m = 0;
	for (int i = 0; i < len; ++i)    //��ԭ�ַ�����������
	{
		if (letter[j][m] != '\0')
			str[i] = letter[j][m++];
		else
		{
			++j;
			m = 0;
			--i;
		}
	}
}