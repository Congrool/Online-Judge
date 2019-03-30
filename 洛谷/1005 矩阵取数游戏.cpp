//这道区间dp好强，一点点代码就处理了复杂问题
//主要是状态转移方程的设计
//对每一行进行dp，因为行与行之间的分数不相互影响，只要每行的分数最大，总的得分就最大
//区间dp
//dp[i][j] = max(2*dp[i+1][j]+2*a[i],2*dp[i][j-1]+2*a[j])
//说明：dp[i][j] 记录i到j的最大得分，a[i] 指当前行的第i个元素。
//当变化到区间(i,j)时，上一个状态可能是(i+1,j),即取走了a[i];或是(i,j-1),即取走了a[j]
//dp[i][j] = max(2*dp[i+1][j]+2*a[i],2*dp[i][j-1]+2*a[j])
//这个dp就很巧妙了
//它实现了第n次取值时，乘上2^n，因为是从里往外推的。
//因为没用高精度，所以还是WA了
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<memory.h>
using namespace std;
typedef long long ll;
ll n,m;
ll dp[81][81],mat[81][81];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%lld",&mat[i][j]);
		}
	ll ans = 0;
	for(int r = 1; r <= n; r++){	
		memset(dp,0,sizeof(dp));
		for(int len = 1; len <= m; len++)
			for(int i = 1; i+len-1<= m; i++){
				int j = i+len-1;
				dp[i][j] = max(2*dp[i+1][j]+mat[r][i]*2,2*dp[i][j-1]+2*mat[r][j]);
			}
		ans += dp[1][m];
	}
	cout << ans << endl;
}