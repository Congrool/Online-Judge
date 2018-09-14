#include<iostream>
using namespace std;
int N,W;
int obj[100][2];
int dp[100][100];
int solve()
{
	for(int i = 0; i < N; i++)
		dp[i][0] = 0;
	for(int i = 0; i <= W; i++)
		dp[0][i] = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= W; j++)
		{
			if(j < obj[i][0])
				dp[i+1][j] = dp[i][j];
			else
			{
				dp[i+1][j] = max(dp[i][j], dp[i][j-obj[i][0]]+obj[i][1]);
			}
		}
	return dp[N][W];
}
int main()
{
	while( cin >> N >> W)
	{
		for(int i = 0; i < N; i++)
			cin >> obj[i][0] >> obj[i][1];
		cout << solve() << endl;
	}
 } 
