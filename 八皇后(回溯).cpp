#include <stdio.h>

#define rawcol 8      //八皇后问题
int board[9];   //每行皇后放在第几列
int solve = 0;   //当前做的是第几种解
bool check(int raw);
int main()
{
	int raw = 1;  //从第一行开始放置
	board[1] = 0;
	while (raw > 0)
	{
		++board[raw];
		while (check(raw) == false && board[raw] <= rawcol)
			++board[raw];
		if (board[raw] <= rawcol)    //这一行放好了
		{
			if (raw == 8)       //第八行放置成功,开始计算下一种情况
				++solve;
			else    //还没结束，放下一行
			{
				++raw;
				board[raw] = 0;
			}
		}
		else      //这一行没法放
			--raw;
	}
	return 0;
}


bool check(int raw)         //放置第raw行皇后,判断
{
	for (int i = 1; i < raw; ++i)
	{
		if (board[raw] == board[i] || abs(board[raw] - board[i]) == abs(i - raw))
			return false;
	}
	return true;
}