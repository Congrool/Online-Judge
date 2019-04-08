//题目为采草药，实质是01背包问题
//本代码采用记忆化搜索算法，即带记忆数组的动态规划
//每组输入允许采草药的时间T,草药的数量M（M<=100)
//接下来每对数字为各草药的采药时间和价值
//输出最大价值
#include<iostream>
using namespace std;
int yaocao[100][2];
int T = 0;
int M = 0;
int max(int a,int b)
{
	if(a > b)
	 return a;
	else
	 return b;
}
int solve(int i, int j,int mem[])
{
	if(mem[i] != -1)
		return mem[i];
	int res = 0;
	if(i == M)
		res = 0;
	else if(j < yaocao[i][0])
		res = solve(i+1,j,mem);
	else{
		res = max(solve(i+1,j,mem),solve(i+1,j-yaocao[i][0],mem)+yaocao[i][1]);
	}
	if(mem[i] == -1)
		mem[i] = res;
	return res;
		
}
int fun(int T,int M)
{
	int mem[100];
	for(int i = 0; i < 100; i++)
		mem[i] = -1;
	return solve(0,T,mem);
}
int main()
{
	while(cin >> T >> M)
	{
		for(int i = 0; i < M; i++)
			cin >> yaocao[i][0] >> yaocao[i][1];
		cout << fun(T,M) << endl; 
	}
}
