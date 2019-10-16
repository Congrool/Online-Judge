#include<algorithm>
#include<iostream>
#include<memory.h>
#include<climits>
//此题让我心态爆炸，因为只是个水题
//dp[i]表示i to N 的最大空闲时间，也就是说倒着递推
//状态转移方程为 
//dp[i] = dp[i+1]+1  当i时刻没有任务开始时
//dp[i] = max{dp[i],dp[arr[num].js]}  当i时刻有任务开始时，找出所有此时刻开始的任务之中空闲时间最大的那个任务
//这题倒是给我了一个启发，找状态转移方程的时候，求什么就设什么，比如这题要求最大空闲时间，就设dp[i]表示i to N 的最大空闲时间
using namespace std;
int N,K;
int dp[10001],sum[10001];
struct rw{
	int ks,js;
};
rw arr[10001];
int cmp(rw a, rw b){
	return a.ks > b.ks;
}
int main(){
	cin >> N >> K;
	for(int i = 0; i < K; i++){
		int last,be;
		scanf("%d%d",&be,&last);
		arr[i].ks = be-1;
		arr[i].js = arr[i].ks + last;
		sum[arr[i].ks] ++;
	}
	sort(arr,arr+K,cmp);
	int num = 0;
	for(int i = N-1; i >= 0; i--){
		if(sum[i] == 0)
			dp[i] = dp[i+1]+1;
		else{
			for(int j = 0; j < sum[i]; j++){
				dp[i] = max(dp[i],dp[arr[num].js]);
				num++;
			}
		}
	}
	cout << dp[0] << endl;
}