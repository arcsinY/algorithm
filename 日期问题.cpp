#include <stdio.h>
#include <string.h>
int dayOfMonth[2][13] = { { 0,31,28,31,30,31,30,31,31,30,31,30,31 }, { 0,31,29,31,30,31,30,31,31,30,31,30,31 } };
typedef struct 
{
	int day;
	int month;
	int year;
}date;
int judge(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 1;   //闰年返回1
	else
		return 0;
}
void add(date &t)   //当前日期+1
{
	t.day++;
	if (t.day > dayOfMonth[judge(t.year)][t.month])
	{
		t.day = 1;
		t.month++;
		if (t.month > 12)
		{
			t.month = 1;
			t.year++;
		}
	}
}
int dayNum[5001][13][32];   //dayNum[i][j][k]:从1年1月1日 到 i年j月k日的天数。用这个数组可解决两个日期天数差、一个日期之后n天的日期 等问题
int main()
{
	date start = { 1,1,1 };
	int cnt = 1;
	while (start.year <= 5000)
	{
		add(start);
		dayNum[start.year][start.month][start.day] = cnt++;
	}
	return 0;
}
