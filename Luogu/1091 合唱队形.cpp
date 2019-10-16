/*
这道题的思想主要是遍历每个划分（最高点），分别求左右包含最高点的最长上升子序列和最长下降子序列的长度l,r;
最后由N-(l+r-1),算出最想出列人数
*/
#include<iostream>
#include<climits>
#include<memory.h>
using namespace std;
int N;
int arr[101];
int s[101];
int dp[101];
int arr2[101];
//左半段
int search(int lo,int hi,int aim){
	while(lo <= hi){
		int mid = lo+(hi-lo)/2;
		if(s[mid] < aim)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return lo;
} 
int solve(int lo,int hi){
	for(int i = 1; i <= N; i++)
		s[i] = INT_MAX;
	memset(dp,0,sizeof(dp));
	int ans = 0;
	for(int i = lo; i <= hi; i++){
		int pos = search(lo,i,arr[i]);
		dp[i] = pos;
		s[dp[i]] = min(s[dp[i]],arr[i]);
		ans = max(ans,dp[i]); //这里算ans一点用都没有，因为是包含最高点的最长上升子序列的长度
	}
	return dp[hi];
} 
//右半段，这里我将右半段倒置后转化成求最长上升子序列的长度
int solve2(int lo,int hi){
	memset(arr2,0,sizeof(arr2));
	int arr2size = hi-lo+1;
	for(int i = hi,j = 1; i >= lo; i--,j++)
		arr2[j] = arr[i];
	for(int i = 1; i <= N; i++)
		s[i] = INT_MAX;
	memset(dp,0,sizeof(dp));
	int ans = 0;
	for(int i = 1; i <= arr2size; i++){
		int pos = search(1,i,arr2[i]);
		dp[i] = pos;
		s[dp[i]] = min(s[dp[i]],arr2[i]);
		ans = max(ans,dp[i]);
	}
	return dp[arr2size];
}
int main(){
	while(cin >> N){
		for(int i = 1; i <= N; i++)
			scanf("%d",&arr[i]);
		int z = 0, y = 0;
		int minstu = INT_MAX;
		for(int i = 1;i <= N; i++){
			z = solve(1,i);
			y = solve2(i,N);
			int curmin = N-(z+y-1);
			if(curmin < minstu)
				minstu = curmin;
		}
		cout << minstu << endl;
	}
} 