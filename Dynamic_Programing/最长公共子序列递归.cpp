//找到a,b的最长公共子序列c的大小
#include<iostream>
#include<string>
using namespace std;
string a,b;
int LCS(int m, int n)
{
	if( m == -1 || n == -1)
		return 0;
	if(a[m] == b[n])
	{
		return LCS(m-1,n-1)+1;
	}
	else{
		return max(LCS(m-1,n),LCS(m,n-1));
	}
}
int main()
{
	while(cin >> a >> b)
	{
		 int m = a.length();
		 int n = b.length();
		 cout << LCS(m-1,n-1) << endl;
	}
 } 
