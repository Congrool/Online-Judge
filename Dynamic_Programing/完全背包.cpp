#include<iostream>
using namespace std;
int N, W;  
int obj[100][2];  //obj[MAX_N][2]; [0] is weight,  [1] is value
int dp[100][100]; //dp[MAX_N][MAX_W]; 

//时间复杂度O(n*w^2)的算法 
int solve()
{
	for(int i = 0; i< N ; i++)
		dp[i][0] = 0;
	for(int i = 0; i <= W; i++)
		dp[0][i] = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= W; j++)
			for(int k = 0; k * obj[i][0] <= j; k++)
			{
				dp[i+1][j] = max(dp[i+1][j], dp[i][j- k*obj[i][0]] + k*obj[i][1]);
			}
	return dp[N][W];
}
//优化版本，时间复杂度为O(n*w)
/*
对递推的直观理解
那么对于第i种物品的出现，我们对第i种物品放不放入背包进行决策。
如果不放那么F[i][j]=F[i-1][j]；
如果确定放，背包中应该出现至少一件第i种物品，所以F[i][j]种至少应该出现一件第i种物品,即F[i][j]=F[i][j-C[i]]+W[i]。
为什么会是F[i][j-C[i]]+W[i]？
因为F[i][j-C[i]]里面可能有第i种物品，也可能没有第i种物品。
我们要确保F[i][j]至少有一件第i件物品，所以要预留C[i]的空间来存放一件第i种物品。
*/
int solve2()
{
	for(int i = 0; i< N ; i++)
		dp[i][0] = 0;
	for(int i = 0; i <= W; i++)
		dp[0][i] = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= W; j++)  
		{
			if(j < obj[i][0])
				dp[i+1][j] = dp[i][j];
			else
				dp[i+1][j] = max(dp[i][j],dp[i+1][j-obj[i][0]] + obj[i][1]);
		}
	/*
	另一种简洁的写法
	for(int i = 0; i < N; i++)
		for(int j = obj[i][0]; j <= W; j++){
			dp[i+1][j] = max(dp[i][j],dp[i+1][j-obj[i][0]]+obj[i][1]);
		}
	*/
	return dp[N][W];
 } 
int main()
{
	while (cin >> N >> W)
	{
		for(int i= 0; i < N; i++)
			cin >> obj[i][0] >> obj[i][1];
		cout << solve() << endl;
		cout << solve2() << endl;
	}	
}
