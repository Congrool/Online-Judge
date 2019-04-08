/*
dp数组设置的很巧妙，既降低了求和时的时间复杂度，也同时解决了问题的时间ti对c+1取模的问题
dp[xi][yi][k]记录(0,0)到(xi,yi)点上亮度为k的星星的个数
它还有另一个用处，在输入数据时，首先是记录各个点各亮度有多少颗星星
然后求二维数组的前缀和，(0,0)到(xi,yi)点上亮度为k的星星的个数
根据包容排斥原理的思想,从(x1,y1)到(x2,y2)的亮度为k的星星的个数和为
total = dp[x2][y2][k] - dp[x2][y1-1][k] - dp[x1-1][y2][k] + dp[x1-1][y1-1][k]
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
ll w[100001],dp[101][101][11];
int n,q,c;
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
	n = readnum(),q = readnum(),c = readnum();
	for(int i = 0; i < n; i++){
		int xi = readnum(),yi = readnum(),si = readnum();
		dp[xi][yi][si]++;
	}
	for(int i = 1; i <= 100; i++)
		for(int j = 1; j <= 100; j++)
			for(int k = 0; k <= c; k++){
				dp[i][j][k] += dp[i][j-1][k]+dp[i-1][j][k]-dp[i-1][j-1][k];
			}
	
	int x1i,y1i,x2i,y2i,ti;
	while(q--){
		ti = readnum(),x1i = readnum(),y1i = readnum(),x2i = readnum(),y2i = readnum();
		int ans = 0;
		for(int i = 0; i <= c; i++){
			int tmp = (i+ti)%(c+1);
			ans += tmp*(dp[x2i][y2i][i] - dp[x1i-1][y2i][i] - dp[x2i][y1i-1][i] + dp[x1i-1][y1i-1][i]);
		}
		cout << ans << endl;
	}
	
}