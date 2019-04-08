/*
通过先序遍历和中序遍历，  
推出原二叉树的后续遍历
*/
#include<iostream>
#include<string>
using namespace std;
int charpos(string a, char b)
{
	int i;
	for (i = 0; i<a.length(); i++)
		if (a[i] == b)
			break;
	return i;
}
void solve(int i, int j, string a, string b, string &c,int &now)
{
	if (i > j || i > a.length())	return;
	int pos = charpos(b, a[now++]);
	if (i == j){
		c.append(1, b[i]);
		return;
	}
	solve(i, pos - 1, a, b, c,now);
	solve(pos + 1, j, a, b, c,now);
	c.append(1, b[pos]);
}
int main()
{
	string a;
	string b;
	while (cin >> a >> b)
	{
		int now = 0;
		int al = a.length();
		int bl = b.length();
		string c = "";
		solve(0, al-1, a, b, c,now);
		cout << c << endl;
	}
}
