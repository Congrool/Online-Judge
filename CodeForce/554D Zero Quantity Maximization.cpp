//掌握一个判断浮点数是否相等的新方法
//将分子分母记下，并标准化符号，比如规定若分子不为零，则分子为正；若分子为零，则规定分母为正
//再用最大公约数归一化
//用map记录
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<cctype>
#include<map>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int INT_INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
char readch(){
	char ch = getchar();
	while(isspace(ch))	ch = getchar();
	return ch;
}
int readnum(){
	char ch = getchar();int ans = 0,sign = 1;
	while(ch < '0' || ch > '9'){if(ch == '-') sign = -1; ch = getchar();}
	while('0' <= ch && ch <= '9'){ans = ans*10 + ch-'0'; ch = getchar();}
	return ans*sign;
}
int a[200001],b[200001];
map<PII,int> m;
int n;
void norm(pair<int, int>& p)
{
	if(p.x < 0)
	{
		p.x *= -1;
		p.y *= -1;
	}
	else if (p.x == 0 && p.y < 0)
	{
		p.y *= -1;
	}
	int d = __gcd(abs(p.x), abs(p.y));
	p.x /= d;
	p.y /= d;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		a[i] = readnum();
	for(int i = 1; i <= n; i++)
		b[i] = readnum();
	int count = 0,ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 0){
			if(b[i] == 0) 
				count++;
		}
		else{
			PII p = make_pair(-b[i],a[i]);
			norm(p);
			m[p]++;
			ans = max(ans,m[p]);
		}
	}
	cout << ans+count << endl;
}