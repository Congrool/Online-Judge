/*
TSOJ：1029
小明喜欢滑雪，为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。
小明想知道在一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为 24-17-16-1。当然 25-24-23-...-3-2-1 更长。
事实上，这是最长的一条。
*/
//使用dfs
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int hei[100][100];
int rec[100][100];
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int R, C;
//以x1,y1为起点的最大长度
int solve(int x1, int y1)
{
	if (rec[x1][y1] != 0)
		return rec[x1][y1];
	int x2 = -1, y2 = -1;
	int maxl = 1;
	for (int k = 0; k < 4; k++)
	{
		x2 = x1 + dx[k];
		y2 = y1 + dy[k];
		if (0 <= x2 && x2 < C && 0 <= y2 && y2 < R && hei[x1][y1] > hei[x2][y2])
		{
			int len = 1 + solve(x2, y2);
			if (len > maxl)
				maxl = len;
		}
	}
	if (rec[x1][y1] == 0)
		rec[x1][y1] = maxl;
	return maxl;
}
int main()
{
	while (cin >> R >> C)
	{
		int maxhei = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				cin >> hei[i][j];
				rec[i][j] = 0;
			}
		int maxl = 0;
		//遍历所有起点
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
			{
				int len = solve(i, j);
				if (len > maxl)
					maxl = len;
			}
		cout << maxl << endl;
	}
}
