#include<iostream>
#include<memory.h>
using namespace std;
int T,M;
int arr[101][2];
int dp[101][1001];
int max(int a,int b){
	return a>b?a:b;
}
void solve(){
	for(int i = 1; i <= M; i++)
		for(int j = T; j >= 0; j--){
			if(j >= arr[i][0])
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i][0]]+arr[i][1]);
			else
				dp[i][j] = dp[i-1][j];			
		}
}
int main(){
	while(cin >> T >> M){
		memset(arr,0,sizeof(arr));
		for(int i = 0; i< M; i++)
			scanf("%d%d",&arr[i][0],&arr[i][1]);
		solve();
		cout << dp[M][T] << endl;
	}
} 
