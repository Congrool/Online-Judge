//利用滚动数组
//s循环还是那个s循环
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
int n,mat[10][10];
int dp[2][10][10];
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
int main(){
	n = readnum();
	int xi,yi,wi;
	xi = readnum(),yi = readnum(), wi = readnum();
	while( xi != 0 && yi != 0 && wi != 0){
		mat[xi][yi] = wi;
		xi = readnum(),yi = readnum(), wi = readnum();
	}
	int s = 2;
	for(int s = 2; s <= 2*n; s++)
		for(int i = 1; i <= n; i++)
			for(int k = 1; k <= n; k++){
				int j = s-i,l = s-k;
				if(j < 1 || l < 1) continue;
				int cur = s%2;
				int pre = cur == 0 ? 1:0;
				dp[cur][i][k] = max(dp[pre][i-1][k],max(dp[pre][i][k-1],max(dp[pre][i][k],dp[pre][i-1][k-1])));
				if(i == k && j == l)
					dp[cur][i][k] += mat[i][j];
				else{
					dp[cur][i][k] += mat[i][j] + mat[k][l];
				}
			}
	cout << dp[0][n][n] << endl;
}