#include<iostream>
#include<climits> 
#include<algorithm>
#include<memory.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 5010;
bool vis[MAXN];
int lowc[MAXN];
int cost[MAXN][MAXN]; //顶点从0-n-1
int n,m;
int Prim(){
    int ans = 0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    int minc,p;
    for(int i = 1; i < n; i++) lowc[i]=cost[0][i];
    for(int i = 1; i < n; i++){
        minc = INF;
        p = -1;
        for(int j = 0; j < n; j++){
            if(!vis[j] && minc>lowc[j]){
                minc = lowc[j];
                p = j;
            }
        }
        if(minc == INF) return -1;
        ans+=minc;
        vis[p] = true;
        for(int j = 0;j < n; j++)
            if(!vis[j]&&lowc[j]>cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}
int main(){
    int m;
    cin >> n >> m;
    int u,v,c;
    memset(cost,0x3f,sizeof(cost));
    for(int i = 0; i < m; i++){
        scanf("%d%d%d",&u,&v,&c);
        cost[u-1][v-1] = min(cost[u-1][v-1],c); //处理重边
        cost[v-1][u-1] = cost[u-1][v-1];
    }
    int ans = Prim();
    cout << ans << endl;
}
