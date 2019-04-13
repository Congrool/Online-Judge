#include<iostream>
#include<climits> 
#include<algorithm>
#include"union_find.h"//自己写的并查集
using namespace std;
const int MAX_E = 100;
struct edge{
	int u,v,cost;
};
bool cmp(const edge& e1,const edge& e2){
	return e1.cost < e2.cost;
}
edge es[MAX_E];
int V,E;
int Kruskal(){
	sort(es,es+E,cmp);
	union_find uf; //使用并查集判断是否产生回路：
					//并查集保存连通分量，如果新的边与该边有相同的根，一定会产生回路 
	uf.init(V); 
	int res = 0;
	int cnt = 0;
	for(int i = 0; i < E; i++){
		edge e = es[i];
		if(!uf.same(e.u,e.v)){
			uf.unite(e.u,e.v);
			res += e.cost;
			cnt++;
		}
		if(cnt == n-1) break;
	}
	if(cnt < n-1) return -1;
	return res;
}
int main() {
	
}
