//驾驶卡车行驶L单位的距离，最开始时，卡车上有P单位汽油
//每开一公里需要消耗1单位汽油，消耗完时，卡车无法前进 
//途中有N个加油站，第i个加油站距离起点Ai公里，可以加Bi个单位汽油
//假设卡车容量无限大，问卡车能否到达终点，如果可以，最少加几次油
//能到达终点输出最少加油次数，否则输出-1 
#include<iostream>
#include<queue>
int A[100];//A[MAX_N] 
int B[100];//B[MAX_N]
using namespace std;
int main()
{
	int N,L,P;
	while(cin >> N >> L >> P)
	{
		priority_queue<int> pque;
		for(int i = 0; i < N; i++)
			cin >> A[i];
		for(int i = 0; i < N; i++)
			cin >> B[i];
		int pos = 0;
		int count = 0;
		while(pos < L)
		{
			for(int i = 0; i < N ; i++)
			{
				if(pos < A[i] && A[i] <= pos+P)
					pque.push(B[i]);
			}
			if(pque.empty())
			{
				cout << -1 << endl;
				break;
			}
			pos = pos+P;
			if(pos >= L)
				break;
			P = pque.top();
			pque.pop();
			count++;			
		}
		if(pos >= L)
			cout << count << endl;
	}	
}
