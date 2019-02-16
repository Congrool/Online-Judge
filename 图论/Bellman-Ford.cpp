/*
状态更新方程
d[i] = min{d[j]+(从i到j的边的权值)|e=(i,j)属于E}
d数组记录从起点s到顶点i的最短距离d[i]
E为边集合
O(|E||V|)
*/
#include<iostream>
#include<memory.h>
#include<climits>
using namespace std;
const int MAX_E = 1001;
struct edge{
	int from,to,cost;
};
edge es[MAX_E];
int d[MAX_E];
int V,E;
void BF_1(int s){
	for(int i = 0; i < V; i++){
		d[i] = INT_MAX;
	}
	d[s] = 0;
	while(true){
		bool update = true;
		for(int i = 0; i< E; i++){
			edge e = es[i];
			if(d[e.from] != INT_MAX && d[e.to] > d[e.from] + e.cost){
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
			if(!update) break;
		}
	}
}
//我觉得这个写法比较优雅 
bool BF_2(){
	memset(d,0,sizeof(d));
	
	for(int i =0; i < V; i++)
		for(int j = 0; j < E; j++){
			edge e = es[j];
			if(d[e.to] > d[e.from] + d[e.cost]){
				d[e.to] = d[e.from] + d[e.cost];
				if(i == V-1) return true;
			}
		}
	return false;
}
int main(){
	memset(es,0,sizeof(es));
	int n; 
	cin >> n;
	E = 0,V = 0;
	for(int i = 0; i < n; i++){
		int tf,tt,tc;
		scanf("%d%d%d",&tf,&tt,&tc);
		es[i].from = tf,es[i].to = tt, es[i].cost = tc;
		E++;
	}	
}