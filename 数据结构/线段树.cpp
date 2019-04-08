#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
#include<cstdlib>
#include<ctime>
using namespace std;
const int MAXN = 30;
const int INF = 0x3f3f3f3f;
int arr[MAXN+1];
int segt[(MAXN+1)<<2];
//主要代码
//建立线段树
void build(int node,int l,int r){
    if(l == r){
        segt[node] = arr[l];
        return;
    }
    build(node*2,l,l+(r-l)/2);
    build(node*2+1,l+(r-l)/2+1,r);

    if(segt[node*2] < segt[node*2+1])
        segt[node] = segt[node*2];
    else
        segt[node] = segt[node*2+1];
}
//查询 qb->querybegin qe->queryend nb->nodebegin ne->nodeend
int __query(int node,int qb,int qe,int nb,int ne){
    if(qb > ne || qe < nb) return INF;
    if(qb <= nb && ne <= qe) return segt[node];
    int mid = nb+(ne-nb)/2;
    return min(__query(node*2,qb,qe,nb,mid),__query(node*2+1,qb,qe,mid+1,ne));
}
//更新单个节点  nb->nodebegin ne->nodeend
void updateOne(int node,int index,int val,int nb,int ne){
    if(nb == ne){
        segt[node] += val;
        return;
    }
    int mid = nb+(ne-nb)/2;
    if(index <= mid) updateOne(node*2,index,val,nb,mid);
    else             updateOne(node*2+1,index,val,mid+1,ne);
    segt[node] = min(segt[node*2],segt[node*2+1]);
}

//测试代码
int main(){
    srand(time(NULL));
    for(int i = 1; i <= MAXN; i++){
        arr[i] = rand()%200;
        printf("%5d ",arr[i]);
    }
    cout << endl;
    for(int i = 1; i <= MAXN; i++){
        printf("%5d ",i);
    }
    cout << endl;
    build(1,1,MAXN);
    int T;
    cin >> T;
    while(T--){
        int l,r;
        cin >> l >> r;
        int res = __query(1,l,r,1,MAXN);
        cout << res << endl;
        int index,addval;
        cin >> index >> addval;
        updateOne(1,index,addval,1,MAXN);
        cin >> l >> r;
        res = __query(1,l,r,1,MAXN);
        cout << res << endl;
    }
    
}
