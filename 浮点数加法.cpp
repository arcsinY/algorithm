#include <stdio.h>
#include <string.h>

char a[1000];   //����������
char b[1000];
int floatPart[1000];   //�����С������
int intPart[1000];   //�������������
int main()
{
	while (scanf("%s %s", a, b) != EOF)
	{
		//a,b������������ǰ��С���ں�С����λ�ÿ����˵�����ִ�
		int aPoint = 0, bPoint = 0;
		int aLen = strlen(a), bLen = strlen(b);

		for (int i = 0; i < aLen; ++i)  //��С�����λ��
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

		//С�������
		int cut = abs(aPoint - bPoint);   //a��b�������ֵ�λ����
		if (aPoint > bPoint)   //a���������ֶ࣬b��λ
		{
			for (int i = bLen; i >= 0; --i)   //b�����λ
				b[i + cut] = b[i];
			bLen += cut;
			bPoint += cut;
			for (int i = 0; i < cut; ++i)    //bǰ�油0
				b[i] = '0';
		}
		if(aPoint < bPoint)
		{
			for (int i = aLen; i >= 0; --i)   //a�����λ
				a[i + cut] = a[i];
			aLen += cut;
			aPoint += cut;
			for (int i = 0; i < cut; ++i)    //aǰ�油0
				a[i] = '0';
		}

		//С���������0
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

		//С���������
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

		//�����������
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
		//��ӡ���
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

