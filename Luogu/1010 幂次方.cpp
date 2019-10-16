#include<iostream>
using namespace std;
typedef long long ll;
ll b;
int ws(ll b){  //求b的二进制位数 
	int len = 0;
	while(b){
		b >>= 1;
		len++;
	} 
	return len;
}
ll fz(ll b){ //将b的二进制反转 
	int len = ws(b);
	len -= 1;
	ll res = 0;
	while(b){
		if(b&1){
			res += 1<<len;
		}
		b >>= 1;
		len--; 
	}
	return res;
}
void solve(ll b){ //递归求解 
	int mi = ws(b)-1;
	b = fz(b);
	while(b){
		if(b&1){
			if(mi == 0)
				printf("2(%d)",mi);
			else if(mi == 1)
				printf("2");
			else{
				printf("2(");
				solve(mi);
				printf(")");
			}
			if(b >> 1)
				printf("+");
		}
		b >>= 1;
		mi--;
	}
}
int main(){
	while(cin >> b){
		solve(b);
		cout << endl;
	}
}
