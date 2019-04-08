//不知道什么原理
//好像用到了下面的公式
//a^b % m == (a+m)^b % m
#include<iostream>
#include<memory.h>
using namespace std;
typedef long long ll;
ll ksm(ll a,ll b){
	ll r = 1, base = a;
	while(b != 0){
		if(b&1)
			r = (r * base )% 10000;		
		base = (base * base) % 10000;
		b >>= 1;
	}
	return r;
} 
ll rec[10001];
int main(){
	int n;
	cin >> n;
	while(n--){
		ll a,b;
		cin >> a >> b;
		ll res = 0;
		memset(rec,0,sizeof(rec));
		for(int i = 1; i <= 10000; i++){
			rec[i] += (rec[i-1] + ksm(i,b))%10000;
		}
		res = ((a/10000)*rec[10000] + rec[a%10000] )%10000;
		cout << res << endl;
	}	
}
