//第一道蓝题，有点激动
//主要使用dijkstra + 二分
//每次跑最短路的时候给一个限制，即路线上每个城市的最大收费，然后按照血量跑最短路
//意外的是居然是WA在了二分上很多次，看来二分的很多细节并没有理解
//这里dijkstra使用了vis数组（记录每个结点是否访问过）优化，因为是无向图会有很多重复
//这个优化也有点意思
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int MAX_V = 10001;
const int MAX_E = 50001;
int n,m,b;
int f[MAX_V],f2[MAX_V],d[MAX_V];
bool vis[MAX_V];
struct edge{
	int to,dhp;
};
vector<edge> G[MAX_V];
bool dijkstra(int maxw){
	if(f[1] > maxw || f[n] > maxw) return false;
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	priority_queue<P,vector<P>,greater<P> > que;
	d[1] = 0;
	vis[1] = 1;
	que.push(P(0,1));
	while(!que.empty()){
		P p = que.top();
		int v = p.second;
		que.pop();
		if(d[v] < p.first) continue;
		for(int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.dhp && f[v] <= maxw){
				d[e.to] = d[v] + e.dhp;
				if(!vis[e.to]){   
					vis[e.to] = true;
					que.push(P(d[e.to],e.to));
				}
			}
		}
	}
	if(d[n] < b) return true;
	else return false;
}
int read(){
	char ch = getchar();
	int ans = 0;
	while(ch < '0' || ch > '9') ch=getchar();
	while('0' <= ch && ch <= '9'){ans = ans*10 + ch-'0'; ch = getchar();}
	return ans;
}
int main(){
	n = read(),m = read(),b = read();
	for(int i = 1; i <= n; i++){
		f[i] = read();
		f2[i] = f[i];
	}
	sort(f2+1,f2+1+n);
	for(int i = 1; i <= m ;i++){
		edge e1,e2;
		int from = read();
		e1.to = read(),e1.dhp = read();
		if(e1.to == from) continue;
		e2.to = from,e2.dhp = e1.dhp;
		G[from].push_back(e1);
		G[e1.to].push_back(e2);	
	}
	int l = 1, r = n,ans = 0;
	if(dijkstra(f2[n]) == false){
		 cout << "AFK" << endl;
		 return 0;
	}
	while(l <= r){
		int mid = l+(r-l)/2;
		if(dijkstra(f2[mid])){
			r = mid-1;
		}
		else{ 
			l = mid+1;
		}
	}
	cout << f2[l] << endl;
}
