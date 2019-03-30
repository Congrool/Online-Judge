#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cctype>
#include<string>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN = 20;
struct BigInteger{
	int num[MAXN],len;
	BigInteger(const string &a){
		len = 0;
		memset(num,0,sizeof(num));
		for(int i = a.size()-1; i >= 0; --i){
			num[len++] = a[i]-'0';
		}
	}
	BigInteger(const ll n){
		memset(num,0,sizeof(num));
		if(n == 0){
			len = 1;
		}
		else{
			int tmp;
			ll nn = n;
			while(n){
				tmp = nn%10;
				num[len++] = tmp;
				nn /= 10;
			}
		}
	}
	BigInteger():len(0){}
	BigInteger operator = (const BigInteger &a){
		memset(this->num,0,sizeof(this->num));
		for(int i = 0; i < a.len; i++){
			num[i] = a.num[i];
		}
		len = a.len;
		return *this;
	}
	BigInteger operator + (const BigInteger &a){
		BigInteger res(0);
		int i = 0,l = max(a.len,this->len),w = 0,tmp;
		for(i = 0; i < l; i++){
			tmp = num[i]+a.num[i];
			res.num[i] = tmp%10 + w;
			w = tmp/10;
		}
		if(w != 0)	res.num[i++] = w;
		res.len = i;
		return res;
	}
	BigInteger operator * (const BigInteger &a){
		BigInteger res(0);
		if((len == 1 && num[0] == 0)||(a.len == 1 && a.num[0] == 0)) return res;
		int l = len + a.len - 1;
		for(int i = 0; i < len; i++)
			for(int j = 0; j < a.len; j++){
				res.num[i+j] += num[i]*a.num[j];
			}
		int w = 0;
		for(int i = 0; i < l; i++){
			res.num[i] += w;
			w = res.num[i]/10;
			res.num[i] %= 10;
		}
		if(w > 0){
			res.len = l+1;
			res.num[l] = w;
		}
		else	res.len = l;
		return res;
	}
	bool operator > (const BigInteger &a) const{
		if(len < a.len) return false;
		else if(len > a.len) return true;
		for(int i = len-1; i >= 0; --i){
			if(num[i] == a.num[i]) continue;
			else if(num[i] > a.num[i]) return true;
			else return false;
		}
		return false;
	}
	void show(){
		for(int i = len-1; i >= 0; --i){
			printf("%d",num[i]);
		}
	}
};
int main(){
	string a,b;
	cin >> a >> b;
	BigInteger num1(a),num2(b),res;
	res = num1*num2;
	res.show();
}