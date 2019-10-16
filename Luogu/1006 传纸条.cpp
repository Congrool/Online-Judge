//多维动态规划
//dp[i][j][k][l] 记录 传到(i,j)从另一条路传到(k,l)的最大好心值
//状态转移方程
//dp[i][j][k][l] = max4(dp[i-1][j][k-1][l],dp[i][j-1][k-1][l],dp[i-1][j][k][l-1],dp[i][j-1][k][l-1])+stu[i][j]+stu[k][l]
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
int dp[51][51][51][51],stu[51][51];
int n,m;
int readnum(){
	char ch = getchar();
	int ans = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while('0' <= ch && ch <= '9'){
		ans = ans*10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
int max4(int a,int b,int c,int d){
	return max(a,max(b,max(c,d)));
}
int main(){
	m = readnum(), n = readnum();
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++){
			stu[i][j] = readnum();
		}
	
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= m; k++)
				for(int l = 1; l <= n; l++){
					if(k == i && j == l) continue;
					else dp[i][j][k][l] = max4(dp[i-1][j][k-1][l],dp[i][j-1][k-1][l],dp[i-1][j][k][l-1],dp[i][j-1][k][l-1])+stu[i][j]+stu[k][l];
					
				}
	cout << dp[m][n-1][m-1][n] << endl; //因为dp[m][n][m][n] 在上面的循环中被跳过了
										//dp[m-1][n][m][n-1] 答案相同
}