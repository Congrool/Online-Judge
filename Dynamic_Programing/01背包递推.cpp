#include<iostream>
#include<memory.h>
using namespace std;
int N,W;
int obj[100][2];
int dp[100][1001];
void solve() 
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= W; j++)
			if(j < obj[i][0])
				dp[i+1][j] = dp[i][j];
			else
				dp[i+1][j] = max(dp[i][j], dp[i][j-obj[i][0]]+obj[i][1]);
}
int main()
{
	while( cin >>W>> N)
	{
		memset(obj,0,sizeof(obj));
		for(int i = 0; i < N; i++)
			cin >> obj[i][0] >> obj[i][1];
		solve();
		cout << dp[N][W]<<endl;
	}
 } 