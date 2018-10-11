/*
回文字符串就是从前往后读和从后往前读都一样的字符串。
比如 abcba, aaa, QoQ。现在给你一个字符串，你可以从中删去一些字符，在不改变原来字符相对顺序的情况下，得到一个最长的回文字符串。
比如 abxdba, 删去字符 x 后，可以得到 abdba，是一个回文字符串。
你的任务就是求出给定的字符串删去若干字符后可以得到的最长的回文字符串的长度。
字符串长度不超过 1000，字符范围为 ‘a’ 到 ‘z’。
*/
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string a;
int dp(int i,int j)
{
	int res = 0;
	if(i == j){
		res = 1;
	}
	else if(j < i){
		res = 0;
	}
	else if(a[i] == a[j]){
		res = 2+dp(i+1,j-1);
	}
	else{
		res = max(dp(i+1,j),dp(i,j-1));
	}
	return res;
}
int main()
{
	while(cin >> a)
	{
		cout << dp(0,a.length()-1) << endl;
	}
}
