#include<iostream>
#include<climits>
#include<memory.h>
using namespace std;
int arr[101];
int dp[101][10001];
int f[10001]; 
int M,N;
//solve1
//dp[i][j]表示前i个菜品花完j元的方案数 
//使用二维数组，并讨论三种情况，
//当arr[i] == j时，dp[i+1][j] = dp[i][j]+1;
//当arr[i] > j时,dp[i+1][j] = dp[i][j];
//当arr[i] < j时,dp[i+1][j] = dp[i][j] + dp[i][j-arr[i]]  当添加菜品i时出现了新的方案数dp[i][j-arr[i]] 
int solve1(){
	memset(dp,0,sizeof(dp));
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= M; j++){
			if(arr[i] > j) 
				dp[i+1][j] = dp[i][j];
			else if(arr[i] == j)
				dp[i+1][j] = dp[i][j]+1;
			else
				dp[i+1][j] = dp[i][j-arr[i]] + dp[i][j];
		}
	return dp[N][M];	
}
//solve2 
//将dp数组压缩到一维， 要么保留1，要么保留2，两段代码是一个意思，当j == arr[i] 时，方法数加一
//状态转移方程f[j] += f[j-arr[i]] 
int solve2(){
	memset(f,0,sizeof(f));
/*1*/ f[0] = 1;
	for(int i = 0; i < N; i++)
		for(int j = M; j >= arr[i];j--){
		/*2
			if(arr[i] == j)
				f[j]+=1;
		*/	f[j] += f[j-arr[i]];
		}
	return f[N];
}
int main(){
	while(cin >> N >> M){
		for(int i = 0; i < N; i++)
			scanf("%d",&arr[i]);
		cout << solve1() << endl;
		cout << solve2() << endl;
	}
} 
