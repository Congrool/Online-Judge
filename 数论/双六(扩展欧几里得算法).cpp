//一个双六上面有向前向后无限延续的各自，每个格子都写有整数。
//其中0号格子是起点，1号格子是终点。
//而骰子上只有a,b,-a,-b四个整数，所以根据a,b的值的不同，有可能无法到达终点。
//掷出四个整数各多少次可以到达终点呢
//如果解不唯一，输出任意一组，如果无解，输出-1
#include<iostream>
using namespace std;
int ExtendGCD(int a,int b,int &x, int &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = ExtendGCD(b,a%b,y,x);
	y -= (a/b)*x;
	return r;
}
int main()
{
	int a,b;
	while(cin >> a >> b)
	{
		int x = 0; int y = 0;
		int gcd = ExtendGCD(a,b,x,y);
		int res[4];
		if(gcd == 1){
			if(x > 0)
			{
				res[0] = x;
				res[2] = 0;
			}
			else
			{
				res[0] = 0;
				res[2] = -x;
			}
			if(y > 0)
			{
				res[1] = y;
				res[3] = 0;
			}
			else
			{
				res[1] = 0;
				res[3] = -y;
			}
			for(int i = 0; i < 4; i++)
				cout << res[i];
		}
		else
			cout << -1 ; 
		cout << endl;		
	}
}
