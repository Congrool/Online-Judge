#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<climits>
using namespace std;
char a[101],b[101];
int dp[101][101];
int al,bl;
//这道题本身不难，少了一段初始化，调试了一个多小时
//状态转移方程
//dp[i][j] = max{dp[i-1][j-1]+map(i,j),dp[i][j-1]+map(0,j),dp[i-1][j]+map(i,0)}
const int wei[6][6] = {0,0, 0, 0, 0, 0,
					   0,5,-1,-2,-1,-3,
					   0,-1,5,-3,-2,-4,
					   0,-2,-3,5,-2,-2,
					   0,-1,-2,-2,5,-1,
					   0,-3,-4,-2,-1,0};
int tolist(char d){
	int list = 0;
	switch(d){
		case 'A': list = 1;break;
		case 'C': list = 2;break;
		case 'G': list = 3;break;
		case 'T': list = 4;break;
		default: list = 5;
	}
	return list;
}
int map(int i,int j){
	int numa = 5 ,numb = 5;
	if(i == 0) numb = tolist(b[j]);
	else if(j == 0) numa = tolist(a[i]);
	else {
		numa = tolist(a[i]),numb = tolist(b[j]);
	}
	return wei[numa][numb];
}
int solve(){
	//init start
	//很重要！
	for(int i = 1; i <= al; i++)
		for(int j = 1; j <= bl; j++)
			dp[i][j] = -2e8;
	for(int i = 1; i <= al; i++) 
		dp[i][0] = dp[i-1][0] + map(i,0);
	for(int i = 1; i <= bl; i++)
		dp[0][i] = dp[0][i-1] + map(0,i);
	//init end;
	for(int i = 1; i <= al; i++)
		for(int j = 1; j <= bl; j++){
			dp[i][j] = max(dp[i][j],dp[i-1][j]+map(i,0));
			dp[i][j] = max(dp[i][j],dp[i][j-1]+map(0,j));
			dp[i][j] = max(dp[i][j],dp[i-1][j-1]+map(i,j));
		}
	return dp[al][bl];
}
char read(){
	char tmp = getchar();
	while(isspace(tmp)){
		tmp = getchar();
	}
	return tmp;
}
int main(){
	cin >> al;
	for(int i = 1; i <= al; i++)
		a[i] = read();
	cin >> bl;
	for(int i = 1; i <= bl; i++)
		b[i] = read();
	cout << solve() << endl;
}