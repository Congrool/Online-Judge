#include<iostream>
#include<memory.h>
using namespace std;
int T, M;
int cy[10001][2];
int dp[101][100001];
//采用了压缩dp，将dp数组的药草种类减少，以节省空间
//方法是将新元素覆写到之前不用的数组空间中
void solve() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j <= T; j++) {
			int ni = i >= 100 ? i % 100 : i;
			int afi = ni == 99 ? 0 : ni + 1;
			if (cy[i][0] <= j) {
				dp[afi][j] = max(dp[ni][j], dp[afi][j - cy[i][0]] + cy[i][1]);
			}
			else
				dp[afi][j] = dp[ni][j];
		}
}
int main() {
	while (cin >> T >> M) {
		for (int i = 0; i < M; i++)
			//scanf("%d%d", &cy[i][0], &cy[i][1]);
			cin >> cy[i][0] >> cy[i][1];
		solve();
		cout << dp[M%100][T] << endl;
	}
}
