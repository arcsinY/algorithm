#include <stdio.h>

#define rawcol 8      //�˻ʺ�����
int board[9];   //ÿ�лʺ���ڵڼ���
int solve = 0;   //��ǰ�����ǵڼ��ֽ�
bool check(int raw);
int main()
{
	int raw = 1;  //�ӵ�һ�п�ʼ����
	board[1] = 0;
	while (raw > 0)
	{
		++board[raw];
		while (check(raw) == false && board[raw] <= rawcol)
			++board[raw];
		if (board[raw] <= rawcol)    //��һ�зź���
		{
			if (raw == 8)       //�ڰ��з��óɹ�,��ʼ������һ�����
				++solve;
			else    //��û����������һ��
			{
				++raw;
				board[raw] = 0;
			}
		}
		else      //��һ��û����
			--raw;
	}
	return 0;
}


bool check(int raw)         //���õ�raw�лʺ�,�ж�
{
	for (int i = 1; i < raw; ++i)
	{
		if (board[raw] == board[i] || abs(board[raw] - board[i]) == abs(i - raw))
			return false;
	}
	return true;
}