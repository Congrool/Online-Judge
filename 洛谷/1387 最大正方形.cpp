//多维动态规划
//状态转移方程：d[i][j] = min{d[i][j-1],d[i-1][j],d[i][j]}+1
//设计状态转移方程好难啊
#include<iostream>
#include<climits>
#include<memory.h>
#include<cctype>
#include<algorithm>
using namespace std;
int rec[101][101];
int d[101][101];
int n,m;
int read(){
	char ch = getchar();
	while(isspace(ch)) ch = getchar();
	return ch-'0'; 
}
int dp(){
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(rec[i][j] == 1){
				d[i][j] = min(d[i-1][j],min(d[i][j-1],d[i-1][j-1]))+1;
				ans = max(d[i][j],ans);
			}
		}
	return ans;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1;j <= m; j++){
			rec[i][j] = read();
			if(rec[i][j] == 1)
				d[i][j] = 1;
		}
	int res = dp();
	cout << res << endl;	
}