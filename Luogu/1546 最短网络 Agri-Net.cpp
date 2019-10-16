/*
快读+最小生成树
感单！
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
int cost[101][101];
bool used[101];
int mincost[101];
int N;
int INF = 0x7777777;
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while('0' > ch || ch > '9') {
		if(ch == '-')  w = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		s = s*10 + ch - '0';
		ch = getchar();
	}
	return s*w;
} 
int prim(){
	fill(used,used+1+N,false);
	fill(mincost,mincost+1+N,INF);
	mincost[0] = 0;
	int res = 0;
	
	while(true){
		int v = -1;
		for(int u = 0; u < N; u++){
			if(!used[u] && (v == -1 || mincost[u] < mincost[v]))
				v = u;
		}
		if(v == -1) break;
		used[v] = true;
		res += mincost[v];
		for(int u = 0; u < N; u++)
			mincost[u] = min(mincost[u],cost[v][u]);
	}
	return res;
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			cost[i][j] = read();
		}
	int res = prim();
	cout << res << endl;
}