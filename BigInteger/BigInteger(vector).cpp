//自己写的大整数，貌似效率很低
//并不支持输入输出流
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace  std;
typedef long long ll;
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
int main(){
	string num1,num2;
	cin >> num1 >> num2;
	BigInteger a(num1),b(num2);
	a = a+b*a;
	a.show();
}