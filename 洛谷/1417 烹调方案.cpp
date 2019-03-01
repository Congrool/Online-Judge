/*
贪心排序
先x后y:a[x]-(p+c[x])*b[x]+a[y]-(p+c[x]+c[y])*b[y]
先y后x:a[y]-(p+c[y])*b[y]+a[x]-(p+c[y]+c[x])*b[x]
化简之后
x > y 的条件是c[x]*b[y]<c[y]*b[x]
然后再按照01背包做
然而我不知道为啥最后要ans = max(ans,d[n][i])
*/

#include<iostream>
#include<climits>
#include<memory.h>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long ll;
ll d[51][100001];
int n,T;
int read(){
	char ch = getchar();
	int ans = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while('0' <= ch && ch <= '9'){
		ans = ans*10 + ch-'0';
		ch = getchar();
	}
	return ans;
}
struct food{
	ll a,b,c;
};
bool cmp(const food &x, const food &y){
	return x.c*y.b < y.c*x.b;
}
food f[51];
ll rec[100001];
int main(){
	cin >> T >> n;
	for(int i = 1; i <= n; i++) f[i].a = read();
	for(int i = 1; i <= n; i++) f[i].b = read();
	for(int i = 1; i <= n; i++) f[i].c = read();
	sort(f+1,f+1+n,cmp);
    memset(d,255,sizeof(d));
    d[0][0] = 0;
	for(ll i = 1; i <= n ; i++)
		for(ll j = 0 ; j <= T; j++){
			if(f[i].c <= j)
				d[i][j] = max(d[i-1][j], d[i][j-f[i].c]+ f[i].a - j*f[i].b);
			else
				d[i][j] = d[i-1][j];
		}
	ll ans = 0;
	for(ll i = 0; i<=T;i++){
		ans = max(ans,d[n][i]);
	}
	cout << ans << endl;
}
