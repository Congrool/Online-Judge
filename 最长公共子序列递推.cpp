#include<iostream>
#include<string>
#include<stack>
using namespace std;
string a,b;
int dp[100][100];   //dp[aMaxLength][bMaxLength];
int reco[100][100]; //recode LCS, 1 : 斜下，2 : 右， 3 : 下 
int solve(int m, int n)
{
	for(int i = 0; i < m; i++)
		dp[i][0] = 0;
	for(int i = 0; i < n; i++)
		dp[0][i] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++) 
		{
			if(a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
				reco[i][j] = 1;
			}
			else
			{
				if(dp[i-1][j] >= dp[i][j-1])
				{
					dp[i][j] = dp[i-1][j];
					reco[i][j] = 2;
				}
				else
				{
					dp[i][j] = dp[i][j-1];
					reco[i][j] = 3;
				}
			} 
		}
	return dp[m][n]; 
}
int main()
{
	while(cin >> a >> b)
	{
		int m = a.length();
		int n = b.length();
		cout << solve(m,n) << endl;
		stack<char> result;
		
		for(int i = m; i > 0; i--)
			for(int j = n; j > 0; j--)
			{
				if(reco[i][j] == 1)
				{
					result.push(a[i-1]);
					i--;
					j--;
				}
				else if(reco[i][j] == 2)
				{
					result.push(a[i-1]);
					i--;
				}
				else if(reco[i][j] == 3)
				{
					result.push(a[i-1]);
					j--;
				}			
			}
		while(!result.empty())
		{
			cout << result.top();
			result.pop();
		}
		cout << endl;
	}
}
