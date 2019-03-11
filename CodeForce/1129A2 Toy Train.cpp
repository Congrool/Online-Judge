//太强了，这是参考网上的做法
//我只能想到模拟版本，ac数据阉割版
//总的来说是贪心，每次选取离当前车站最远的糖果
//dist[i]记录车站i的所有糖果的目的地中，到i最近的距离
//从车站s出发，假设终点车站为e
//有方程 ans = max{len(s,i)+n*num[i]+len(i,e)|i = 1,2,3...,n}
//ans 就是从车站s开始的最短时间
//n*num[i]是要走的圈数
#include<queue>
#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
int dist[5001],num[5001];
int read(){
	char ch = getchar();
	int ans = 0;
	while(ch < '0' || ch > '9') ch =getchar();
	while('0' <= ch && ch <= '9'){ans = ans*10+ch-'0'; ch = getchar();}
	return ans;
}
inline int jl(int a,int b){
	return b >= a?b-a:b+n-a;
}
int main(){
	n = read(), m = read();
	memset(dist,0x3f,sizeof(dist));
	for(int i = 1; i <= m; i++){
		int ai = read(), bi = read();
		if(ai == bi) continue;
		if(bi > ai) dist[ai] = min(dist[ai],bi-ai);
		else dist[ai] = min(dist[ai],bi-ai+n);
		num[ai]++;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = 0;
		for(int j = 1; j <= n; j++){
			if(num[j]>0)
			ans = max(ans,jl(i,j)+n*(num[j]-1)+dist[j]);
		}
		printf("%d ",ans);
	}
}