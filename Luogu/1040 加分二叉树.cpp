//区间dp
//状态转移方程：
//d[i][j] = max(d[i][k-1]*d[k+1][j]+d[k][k],d[i][j])
//其中d数组记录由i到j能构成的最大加分二叉树
//每次更新数值时记录根结点，root[i][j] = k  即i到j的根为k
#include<iostream>
#include<algorithm>
using namespace std;
int d[35][35];
int arr[31];
int root[35][35];
int n;
void init() {
	for (int i = 1; i <= n; i++) {
		d[i][i] = arr[i];
		d[i][i - 1] = 1;
	}
}
void dp() {
	for(int len = 1; len <= n; len++)
		for (int i = 1; i + len <= n; i++) {
			int j = i + len;
			for (int k = i; k <= j; k++) {
				if (k + 1 > j) break;
				int tmp = d[i][k - 1] * d[k + 1][j] + d[k][k];
				if (tmp > d[i][j]) {
					d[i][j] = tmp;
					root[i][j] = k;
				}
			}

		}
}
void preorder(int l, int r) {
	if (l > r) return;
	if (l == r) printf("%d ", l);
	else {
		printf("%d ", root[l][r]);
		preorder(l, root[l][r] - 1);
		preorder(root[l][r] + 1, r);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		root[i][i] = i;
	}
	init();
	dp();
	printf("%d\n", d[1][n]);
	preorder(1, n);
}