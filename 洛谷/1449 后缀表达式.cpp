/*
后缀表达式求值
*/ 
#include<iostream>
#include<stack>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
string expr;
int todigit(char num){
	return num-'0';
}
int getnum(int &pos){
	stack<int> topro;
	for(;expr[pos] != '.';pos++){
		int cur = todigit(expr[pos]);
		topro.push(cur);
	}
	int wei = 1;
	int res = 0;
	while(!topro.empty()){
		int cur = topro.top();
		res+=cur*wei;
		wei*=10;
		topro.pop();
	}
	return res;
}
int main()
{
	while(cin >> expr){
		stack<int> num;
		stack<char> oper;
		for(int i = 0; i < expr.length()-1; i++){
			if(isdigit(expr[i])){
				int temp = getnum(i);
				num.push(temp);						
			}
			i++;
			while(i < expr.length() && !isdigit(expr[i])){
				char op = expr[i];
				int num1 = num.top();
				num.pop();
				int num2 = num.top();
				num.pop();
				int res = 0;
				switch(op){
					case '+':
						res = num2+num1;
						break;
					case '-':
						res = num2 - num1;
						break;
					case '*':
						res = num2*num1;
						break;
					case '/':
						res = num2/num1;
						break;
					}
				num.push(res);
			}
		}
		cout << num.top()<< endl;
	}
	
}
