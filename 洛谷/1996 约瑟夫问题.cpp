/*
约瑟夫问题，用队列解决效率很高 
*/ 
#include<iostream>
#include<memory.h>
#include<climits>
#include<queue>
using namespace std;
int main()
{
	int n,m;
	while(cin >> n >> m){
		queue<int> que;
		for(int i = 1; i <= n; i++)
			que.push(i);
		int count = 1;
		while(!que.empty()){
			if(count % m == 0){
				cout << que.front() <<" ";
				que.pop();
			}
			else{
				int temp = que.front();
				que.pop();
				que.push(temp);
			}
			count++;
		}
		cout << endl;	
	}
}
