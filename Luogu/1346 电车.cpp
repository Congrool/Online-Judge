//dijkstra算法解决
//感单！
#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
typedef pair<int,int> P;
int N;
int d[101];
struct edge{
	int to,cost;
};
vector<edge> G[101];
void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+N+1,INT_MAX);
	d[s] = 0;
	que.push(P(0,s));
	
	while(!que.empty()){
		P p = que.top();que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	} 
}
int main(){
	cin >> N;
	int sta,end;
	cin >> sta >> end;
	for(int i = 1; i <= N; i++){
		int ki;
		cin >> ki;
		for(int j = 0; j < ki; j++){
			int tmp_to;
			cin >> tmp_to;
			edge tmp;
			if(j == 0) tmp.cost = 0;
			else tmp.cost = 1;
			tmp.to = tmp_to;
			G[i].push_back(tmp);
		}
	}
	dijkstra(sta);
	if(d[end] == INT_MAX) cout << -1 << endl;
	else cout << d[end] << endl;
}