#include<iostream>
#include<memory.h>
using namespace std;
int N;
int hang[14], lie[14], zhu[26], fu[26];
int numofcheese = 0;
int maxnum = 0;
//这是我一开始想到的算法，用二层循环递归
//时间复杂度实在太高 
/*
void dfs(int cx,int cy) {
	if (numofcheese > maxnum) {
		maxnum = numofcheese;
	}
	for (int i = cx+1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			int ijzhu = i>j ? (N+j-i-1):(j+N-i);
			int ijfu = (i + j<N) ? i + (j - 1) : j + (i - 1);
			if (!hang[i] && !lie[j] && !zhu[ijzhu] && !fu[ijfu]) {
				hang[i] = 1, lie[j] = 1, zhu[ijzhu] = 1, fu[ijfu] = 1;
				numofcheese++;
				dfs(i,j);
				numofcheese--;
				hang[i] = 0, lie[j] = 0, zhu[ijzhu] = 0, fu[ijfu] = 0;
			}
		}
	return;
}*/
//这是借鉴了网上地解决方案，主要用到了一个信息，第n个皇后肯定要放在第n行，否则N皇后问题无解
//这就能把一层循环省略掉了 
void dfs(int i) {
	if (i > N) {
		maxnum++;
		if (maxnum <= 3) {
			for (int i = 1; i <= N; i++)
				printf("%d ", hang[i]);
			cout << endl;
		}
		return;
	}
	for (int j = 1; j <= N; j++) {
		int ijzhu = i>j ? (N + j - i - 1) : (j + N - i);
		int ijfu = (i + j<N) ? i + (j - 1) : j + (i - 1);
		if (!lie[j] && !zhu[ijzhu] && !fu[ijfu]) {
			hang[i] = j;
			lie[j] = 1, zhu[ijzhu] = 1, fu[ijfu] = 1;
			dfs(i + 1);
			lie[j] = 0, zhu[ijzhu] = 0, fu[ijfu] = 0;
			hang[i] = 0;
		}
	}
}
int main() {
	while (cin >> N) {
		maxnum = 0;
		numofcheese = 0;
		memset(hang, 0, sizeof(hang));
		memset(lie, 0, sizeof(lie));
		memset(zhu, 0, sizeof(zhu));
		memset(fu, 0, sizeof(fu));
		dfs(1);
		cout << maxnum << endl;
	}
}
