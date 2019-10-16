/*
本质是，求最小环
可以使用并查集
par[n]记录父亲结点，d[i]记录i到根的路径长度
为了效率会更新par[n]，即会直接将某结点连到根上，改变树的形状，
但是d是按未变形状的树来记录的
理解可能还是有问题，但又不知道哪理解错了
反正不能随心所欲地改代码
加个优化都会出错
*/
#include<iostream>
using namespace std;
const int MAX_N = 200001;
int par[MAX_N],d[MAX_N],res;
void init(int n){
	for(int i = 1; i <= n; i++){
		par[i] = i;
		d[i] = 0;
	}
}
int find(int x)
{
    if (par[x]!=x)                       
    {
        int last=par[x];                 
        par[x]=find(par[x]);                 
        d[x]+=d[last];                 
    }
    return par[x];
}
void unite(int x,int y){
	int xx = find(x);
	int yy = find(y);
	if(xx == yy)
		res = min(res,d[x]+d[y]+1);
	else{
		par[xx] = yy;
		d[x] = d[y] + 1;
	}
}
int main(){
	int n;
	cin >> n;
	res = 0x7777777;
	init(n);
	for(int i = 1; i <= n; i++){
		int tmp;
		scanf("%d", &tmp);
		unite(i,tmp);
	}
	cout << res << endl;
}