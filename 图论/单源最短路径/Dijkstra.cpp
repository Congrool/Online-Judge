//dijkstra算法：
//1、找到最短距离已经确定的顶点，从它出发更新相邻顶点的最短距离
//2、此后不需要再关心1中的“最短距离已经确定的顶点” 
//一般来说dijkstra算法比bellman-ford算法更快
//但是dijkstra不能处理负边的情况，这时候还是得用bellman-ford算法 
#include<iostream>
#include<climits>
#include<algorithm>//fill()函数 
#include<queue>
using namespace std;
const int MAX_V = 100;
const int MAX_E = 100;
int V,E;

//有待优化的dijkstra算法 O(|V|^2） 
int d_1[MAX_V];
bool used_1[MAX_V];
int cost_1[MAX_V][MAX_E];//cost[v][u]表示边e = (u,v)的权值，不存在用INF表示 
void dijkstra_1(int s){ //s是起点 
	fill(d_1,d_1+V,INT_MAX);
	fill(used_1,used_1+V,false);
	d_1[s] = 0;
	while(true){
		int v = -1;
		//从尚未使用的顶点中选择一个距离最小的顶点 
		for(int u = 0; u < V; u++) 
			if(!used_1[u] && (v == -1 || d_1[u] < d_1[v]))
				u = v;			
		
		if(v == -1) break;
		used_1[v] = true;
		//更新d_1 
		for(int u = 0; u < V; u++){
			d_1[u] = min(d_1[u],d_1[v]+cost_1[v][u]);
		}
	}
}

//用优先队列优化后的dijkstra算法 O(|E|log|V|) 
struct edge{
	int to,cost;
};
typedef pair<int,int> P;
vector<edge> G[MAX_V];
int d_2[MAX_V];
void dijkstra_2(int s){
	priority_queue<P,vector<P>,greater<P> >que; //这里greater 先按first升序，first相等时按second升序 
	fill(d_2,d_2+V,INT_MAX);
	d_2[s] = 0;
	que.push(P(0,s));
	
	while(!que.empty()){
		P p = que.top();que.pop();
		int v = p.second;
		if(d_2[v] < p.first) continue;
		
		for(int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if(d_2[e.to] > d_2[v] + e.cost){
				d_2[e.to] = d_2[v] + e.cost;
				que.push(P(d_2[e.to],e.to));
			}
		}
	}	
} 
int main(){
	
