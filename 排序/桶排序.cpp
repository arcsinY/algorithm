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
char letter[26][1000];  //每种字母对应一个一位数组，不分大小写共26个字母
int pos[26];   //26个数组的位置
void bucketSort(char* str, int len);
int main()
{
	
	return 0;
}

void bucketSort(char* str, int len)
{
	for (int i = 0; i < len; ++i)  //每个字母放在对应的一维数组中
	{
		if (isupper(str[i]))
			letter[str[i] - 'A'][pos[str[i] - 'A']++] = str[i];
		else
			letter[str[i] - 'a'][pos[str[i] - 'a']++] = str[i];
	}
	int j = 0, m = 0;
	for (int i = 0; i < len; ++i)    //对原字符串重新排序
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