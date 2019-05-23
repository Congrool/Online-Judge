//魔改dijkstra
//求最大乘积路径
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
const int MAXN = 1000010;
const int MOD = 100003;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<double,int> PDI;
bool vis[MAXN];
double d[MAXN];
int N,M;
struct edge{
    int to,cost;
    edge(){}
    edge(int v,int w){
        to = v, cost = w;
    }
};
vector<edge> G[MAXN];
inline void dijkstra(int s){
    memset(d,0,sizeof(d));
    priority_queue<PDI> que;
    que.push(PDI(1.0,s));
    d[s] = 1.0;
    while(!que.empty()){
        PDI p = que.top(); que.pop();
        int u = p.second;
        for(int i = 0; i < G[u].size(); i++){
            edge e = G[u][i];
            if(d[e.to] < d[u]*(0.01*e.cost)){
                d[e.to] = d[u]*(0.01*e.cost);
                que.push(PDI(d[e.to],e.to));
            }
        }
    }
}
int main(){
    scanf("%d%d",&N,&M);
    int x,y,z;
    for(int i = 1; i <= M; i++){
        scanf("%d%d%d",&x,&y,&z);
        edge t(y,100-z);
        edge tt(x,100-z); //把这两步忘了
        G[x].push_back(t);
        G[y].push_back(tt); //然后就Wrong了
    }
    int s,t;
    scanf("%d%d",&s,&t);
    dijkstra(s);
    printf("%.8lf\n",100.0/d[t]);
}