/*
参考的leetcode解法：中心扩展
有2n-1个中心，向两边扩展
一开始的错误思路：将字符串倒置，求最大公共子串
当后面出现子串倒置的副本时，会出错
如“aacdefcaa”
输出“aac”
正解为“aa”
*/
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<memory.h>
using namespace std;
int midexpand(string &s, int lo, int hi) {
	while (0 <= lo && hi < s.length() && s[lo] == s[hi]) {
		lo--;
		hi++;
	}
	return hi - lo - 1;
}
string longestPalindrome(string s) {
	int maxlen = 0;
	int st = 0, te = 0;
	for (int i = 0; i < s.length(); i++) {
		int len1 = midexpand(s, i, i);
		int len2 = midexpand(s, i, i + 1);
		int len = max(len1, len2);
		if (len > te - st && len == len1) {
			maxlen = len1;
			st = i - (len - 1) / 2;
			te = i + (len - 1) / 2;
		}
		else if (len > te - st && len == len2) {
			maxlen = len2;
			st = i - len / 2 + 1;
			te = i + len / 2;
		}
	}
	return s.substr(st, te - st + 1);
}
int main() {
	string s;
	cin >> s;
	cout << longestPalindrome(s) << endl;
}