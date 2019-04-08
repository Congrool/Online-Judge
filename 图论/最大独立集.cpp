//求图的最大独立集
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<cctype>
#include<map>
#include<set>
#include<stdio.h>
using namespace std;
typedef long long ll;
bool vis[101];
int G[101][101],G2[101][101];
int adj[101],dp[101];
int n,m,ans;
int max(int a,int b){
	return a>b?a:b;
}
bool dfs(int *adj,int total,int cnt){  //adj为当前结点的临边数组，total记录临边的数量，cnt为当前团的大小
	if(total == 0){
		if(ans < cnt){
			ans = cnt;
			return true;
		}
		return false;
	}
	int i,j,k,t[101];
	for(i = 0; i < total; i++){
		if(cnt + (total-i) < ans) return false;
		for(j = i+1, k = 0; j < total; j++){
			if(G2[adj[i]][adj[j]]) t[k++] = adj[j];
		}
		if(dfs(t,k,cnt+1)) return true;
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u][v] = 1;
		G[v][u] = 1;
	}
	//求补图
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n ;j++){
			if(G[i][j] == 0 && i != j){
				G2[i][j] = 1;
			}
		}

	int i,j,k;
	for(i = n; i >= 1; i--){  //为什么反着推我也不知道
		for(j = i+1, k = 0; j <= n; j++){
			if(G2[i][j]) adj[k++] = j; //adj记录临边，k是临边数
		}
		dfs(adj,k,1);
	  //dp[i] = ans;
	}
	cout << ans << endl;
}
