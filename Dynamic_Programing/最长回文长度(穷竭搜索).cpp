#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string a;
int maxl = 1;
bool ishui(const string &a)
{
	string af = a;
	reverse(af.begin(),af.end());
	return a == af;			
}
void dp(string &bei)
{
	int len = bei.length();
	if (len == 1)
		return;
	for(int i = 0; i < len; i++)
	{
		string b = bei;
		b.erase(i, 1);
		if(ishui(b))
		{
			if(b.length() > maxl)
				maxl = b.length();
		}
		else 
			dp(b);		
	}
}
int main()
{
	while(cin >> a)
	{
		maxl = 1;
		string bei = a;
		dp(bei);
		cout << maxl << endl;
	}
 } 
