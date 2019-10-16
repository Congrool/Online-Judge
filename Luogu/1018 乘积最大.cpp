//dfs过的
//主要是大整数
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
ll num[41],n,k;
ll readnum(){
	char ch = getchar();
	ll ans = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while('0' <= ch && ch <= '9'){
		ans = ans*10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
struct BigInteger{
	int len;
	vector<int> num;
    BigInteger(const string& str){
        for(int i = str.size()-1; i >= 0; i--)
            num.push_back(str[i]-'0');
        len = str.size();
    }
    BigInteger(const ll& n = 0){
		ll tmp = n;
		while(tmp){
			num.push_back(tmp%10);
			tmp /= 10;
		}
		len = num.size();
    }
	BigInteger operator *(const BigInteger &b) const{
		int len = num.size() + b.num.size()-1;
		int tmp[50];
		BigInteger c;
		memset(tmp,0,sizeof(tmp));
		for(int i = 0; i < num.size(); i++)
			for(int j = 0; j < b.num.size(); j++)
				tmp[i+j] += num[i]*b.num[j];
		int q = 0;
		for(int i = 0; i < len; i++){
			tmp[i] += q;
			q = tmp[i]/10;
			tmp[i] %= 10;
		}
		while(q > 0){
			tmp[len++] = q%10;
			q /= 10; 
		}
		for(int i = 0; i < len; i++){
			c.num.push_back(tmp[i]);
		}
		return c;
	}
	BigInteger operator +(const BigInteger &b) const{
		BigInteger c;
		c.num.clear();
		for(int i = 0, g = 0; ; i++){
			if(g == 0 && i >= num.size() && i >= b.num.size()) break;
			int x = g;
			if(i < num.size()) x += num[i];
			if(i < b.num.size()) x += b.num[i];
			c.num.push_back(x%10);
			g = x / 10;
		}
		return c;
	}
	BigInteger operator =(const BigInteger &b){
		vector<int> tmp;
		this->num.clear();
		for(int i = 0; i < b.num.size(); i++){
			this->num.push_back(b.num[i]);
		}
		this->len = b.len;
		return *this;
	}
    void show(){
        vector<int>::iterator it = num.end();
        for(--it; it != num.begin(); --it){
            printf("%d",*it);
        }
        printf("%d",*num.begin());
    }
	bool operator >(BigInteger &b){
		if(b.num.size() > num.size())  return false;
		else if(b.num.size() < num.size())  return true;
		else{
			vector<int>::iterator ita = num.end(), itb = b.num.end();
			for(--ita,--itb; ita != num.begin(); --ita,--itb){
				if(*ita == *itb) continue;
				if(*ita > *itb) return true;
				else return false;
			}
			return true;
		}	
	}
};
BigInteger rec[100],ans(0);
BigInteger ONE(1),ZERO(0),TEN(10);
void dfs(int s,int co){
	if(co > k){
		BigInteger tmp(0);
		for(int i = s+1; i <= n; i++){
			//tmp = tmp*10 + num[i];
			BigInteger tmpp(num[i]);
			tmp = tmp*TEN+ tmpp;
		}
		rec[co] = tmp;
		tmp = ONE;
		for(int i = 1; i <=co; i++){
			//tmp *= rec[i];
			tmp = tmp * rec[i];
		}
		//ans = max(tmp,ans);
		if(tmp > ans) ans = tmp;
		rec[co] = ZERO;
		return;
	}
	BigInteger tmp(0);
	for(int i = s+1; i <= n; i++){
		//tmp = tmp*10+num[i];
		BigInteger tmpp(num[i]);
		tmp = tmp * TEN + tmpp;
		rec[co] = tmp;
		dfs(i,co+1);
		rec[co] = ZERO;
	}
}
char readch(){
	char ch = getchar();
	while(isspace(ch)) ch = getchar();
	return ch;
}
int main(){
	n = readnum(), k = readnum();
	for(int i = 1; i <= n; i++){
		char ch = readch();
		num[i] = ch-'0';
	}
	dfs(0,1);
	ans.show();
}