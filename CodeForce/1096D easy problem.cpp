/*
线性动态规划，能想到状态转移方程就不难了（虽然我是偷看的）
st = {' ','h','a','r','d'}
dp[i][j] 是只字符串前i个字符没有前缀子序列"st[1]st[2]..st[j]"的最小代价。
状态转移方程
当str[i] != st[j] dp[i][j] = dp[i-1][j]
当str[i] == st[j] dp[i][j] = min(dp[i-1][j]+w[i],dp[i-1][j-1]) 即去掉str[i]或者留下str[i]
*/
#include<iostream>
#include<memory.h>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
const int INT_INF = 0x3f3f3f3f;
const long long ll_INF = 0x3f3f3f3f3f3f3f3f;
typedef long long ll;
typedef pair<char,int> PCI;
string str;
ll w[100001],dp[100001][5];
int n;
const char word[5] = {' ','h','a','r','d'};
ll readnum(){
	char ch = getchar();
	ll ans = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while('0' <= ch && ch <= '9'){
		ans = ans*10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
int main(){
	cin >> n;
	cin >> str;
	for(int i = 0; i < n; i++){
		w[i] = readnum();
	}
	for(int i = 0; i < n; i++){
		dp[i][0] = ll_INF;
	}
	if(str[0] == 'h')
		dp[0][1] = w[0];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 4; j++){
			if(str[i] == word[j]){
				dp[i][j] = min(dp[i-1][j]+w[i],dp[i-1][j-1]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	ll res = ll_INF;
	for(int i = 1; i < 5; i++){
		res = min(res,dp[n-1][i]);
	}
	cout << res << endl;
	
}