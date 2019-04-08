#include<iostream>
#include<climits>
#include<memory.h>
#include<algorithm>
/*
第一问很明显是求最长不上升子序列的长度
第二问有点难，如果用贪心，复杂度会达到n^2;
我们可以使用dilworth定理，求其反链的最大长度，结果就是最长不上升子序列的最短划分
最长不上升子序列的反链是最长严格上升子序列
可惜是错的
*/
using namespace std;
int s[100001];	  
int arr[100001];
int dp[100001];   
int rec[100001];
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
		if (s[mid] >= aim)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return lo;
}
int solve1() {
	for (int i = 1; i <= num; i++)
		s[i] = INT_MIN;
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	for (int i = 1; i <= num; i++) {
		int pos = search(1, i, arr[i]);  
		dp[i] = pos;
		s[dp[i]] = max(s[dp[i]], arr[i]); 
		ans = max(ans, dp[i]);
	}
	return ans;
}		//这是求最长不上升子序列；
int search2(int lo, int hi, int aim) {
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (s[mid] < aim)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return lo;
}
int solve2() {
	for (int i = 1; i <= num; i++)
		s[i] = INT_MAX;
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	for (int i = 1; i <= num; i++) {
		int pos = search2(1, i, arr[i]);
		dp[i] = pos;
		s[dp[i]] = min(s[dp[i]], arr[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}         //求最长严格上升子序列
int main() {
	int HEI;
	while (cin >> HEI) {
		arr[1+num++] = HEI;
	}
	cout << solve1() << endl;
	cout << solve2() << endl;
}