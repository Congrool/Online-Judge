#include<iostream>
#include<climits> 
#include<algorithm>
using namespace std;
const int MAX_V = 100;
int cost[MAX_V][MAX_V]; //cost[u][v]记录e = (u,v)的权值(不存在的情况设成INF) 
int mincost[MAX_V];		//记录从X出发的边到每个顶点的最小权值 
bool used[MAX_V];		//顶点i是否包含再集合X中 
int V;
int prim(){
	fill(mincost,mincost+V,INT_MAX);
	fill(used,used+V,false);
	mincost[0] = 0;
	int res = 0;
	
	while(true){
		int v = -1;
		for(int u = 0; u < V; u++){
			if(!used[u] && (v == -1 || mincost[u] < mincost[v])) 
				v = u;
		}
		if(v == -1) break;
		used[v] = true;
		res += mincost[v];
		for(int u = 0; u < V; u++)
			mincost[u] = min(mincost[u],cost[v][u]);
		return res;
	}
}
int main() {
	
}