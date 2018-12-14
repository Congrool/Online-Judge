#include<iostream>
#include<climits>
#include<memory.h>
using namespace std;
/*
功能：求最大非严格上升子序列的长度
关于dp和s数组的意义见于代码注释
算法思想：
有两个状态转移方程
dp[i] = max{1,dp[j]+1}其中j = 1,,......,i-1
s[dp[i]] = min{s[dp[i]],arr[i]}
每当扫到一个新的元素时，按O(n^2)的算法，即只使用第一个状态转移方程，
则要检索j,满足1<= j <= i-1,且dp[j]最大，然后才能得到新dp[i]的值。

为了优化时间复杂度，减少检索时间，使用数组s，和第二个状态转移方程
该方程的作用是当遇到一个新元素时，在s中寻找最后一个大于等于s[dp[i]]的下标（可以使用二分查找，因为可以证明s是严格单调上升的数组），
该下标即新dp[i]的值。
*/
int s[100001];	  //s[dp[i]]记录的是长度为dp[i]的子序列的最小元素， 即 s[dp[i]] = min{s[dp[i]],arr[i]}
int arr[100001];
int dp[100001];   //dp[i] 指以arr[i]结尾的最长子序列的长度
int num;
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
int search(int lo, int hi, int aim) {
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (s[mid] <= aim)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return lo;
}
void init() {
	for (int i = 1; i <= num; i++)
		s[i] = INT_MAX;
	memset(dp, 0, sizeof(dp));
}
int solve() {
	init();
	int ans = 0;
	for (int i = 1; i <= num; i++) {
		int pos = search(1, i, arr[i]);  //在s中找到小于等于arr[i]的最后一个元素的下一个坐标
		dp[i] = pos;
		s[dp[i]] = min(s[dp[i]], arr[i]); //每扫一个元素就更新s[i]数组
		ans = max(ans, dp[i]);
	}
	return ans;
}
int main() {
	int HEI;
	while (cin >> HEI) {
		arr[1+num++] = HEI;
	}
	cout << solve() << endl;
}
