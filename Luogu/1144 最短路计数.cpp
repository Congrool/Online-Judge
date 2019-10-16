//观察到本题所有边的权值相等
//符合bfs的条件
//所以直接bfs
//重点在于bfs的写法
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
const int MAXN = 1000010;
const int MOD = 100003;
bool vis[MAXN];
int rec[MAXN],d[MAXN];
vector<int> G[MAXN];
int N,M;
//记录bfs的每个阶段的方法：
//可以重新开一个数组记录，而循环终止的条件就可以简单的用!que.empty()
inline void bfs(){
    vis[1] = true;
    queue<int> que;
    que.push(1);
    d[1] = 0;
    rec[1] = 1;
    while(!que.empty()){
        int x = que.front(); que.pop();
        for(int i = 0; i < G[x].size(); i++){
            int t = G[x][i];
            if(!vis[t]){
                d[t] = d[x] + 1;
                vis[t] = true;
                que.push(t);
            }
            if(d[t] == d[x] + 1){
                rec[t] += rec[x];
                rec[t] %= MOD;
            }
        }
    }    
}
int main(){
    scanf("%d%d",&N,&M);
    int x,y;
    for(int i = 1; i <= M; i++){
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bfs();
    for(int i = 1; i <= N; i++){
        printf("%d\n",rec[i]);
    }
}