#include <stdio.h>
#include <string.h>

char a[1000];   //两个浮点数
char b[1000];
int floatPart[1000];   //结果的小数部分
int intPart[1000];   //结果的整数部分
int main()
{
	while (scanf("%s %s", a, b) != EOF)
	{
		//a,b中整数部分在前，小数在后，小数点位置靠后的说明数字大
		int aPoint = 0, bPoint = 0;
		int aLen = strlen(a), bLen = strlen(b);

		for (int i = 0; i < aLen; ++i)  //找小数点的位置
		{
			if (a[i] == '.')
			{
				aPoint = i;
				break;
			}
		}
		for (int i = 0; i < bLen; ++i)
		{
			if (b[i] == '.')
			{
				bPoint = i;
				break;
			}
		}

		//小数点对齐
		int cut = abs(aPoint - bPoint);   //a和b整数部分的位数差
		if (aPoint > bPoint)   //a的整数部分多，b移位
		{
			for (int i = bLen; i >= 0; --i)   //b向后移位
				b[i + cut] = b[i];
			bLen += cut;
			bPoint += cut;
			for (int i = 0; i < cut; ++i)    //b前面补0
				b[i] = '0';
		}
		if(aPoint < bPoint)
		{
			for (int i = aLen; i >= 0; --i)   //a向后移位
				a[i + cut] = a[i];
			aLen += cut;
			aPoint += cut;
			for (int i = 0; i < cut; ++i)    //a前面补0
				a[i] = '0';
		}

		//小数部分最后补0
		if (aLen != bLen)
		{
			int cut = abs(aLen - bLen);
			if (aLen < bLen)
			{
				for (int i = 0; i < cut; ++i)
					a[aLen + i] = '0';
				aLen += cut;
			}
			if (bLen < aLen)
			{
				for (int i = 0; i < cut; ++i)
					b[bLen + i] = '0';
				bLen += cut;
			}
		}

		//小数部分相加
		int carry = 0;
		for (int i = aLen - 1; i > aPoint; --i)   
		{
			floatPart[i] = a[i]-'0' + b[i]-'0' + carry;
			if (floatPart[i] >= 10)
			{
				floatPart[i] -= 10;
				carry = 1;
			}
			else
				carry = 0;
		}

		//整数部分相加
		for (int i = aPoint - 1; i >= 0; --i)   
		{
			intPart[i] = a[i] - '0' + b[i] - '0' + carry;
			if (intPart[i] >= 10)
			{
				intPart[i] -= 10;
				carry = 1;
			}
			else
				carry = 0;
		}
		//打印结果
		if (carry == 1)
			printf("1");
		for (int i = 0; i < aPoint; ++i)
			printf("%d", intPart[i]);
		printf(".");
		for (int i = aPoint + 1; i < aLen; ++i)
			printf("%d", floatPart[i]);
		printf("\n");
		memset(intPart, 0, sizeof(intPart);
		memset(floatPart, 0, sizeof(floatPart));
	}
	return 0;
}

