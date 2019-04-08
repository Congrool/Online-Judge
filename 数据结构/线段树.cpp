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
int addmark[(MAXN+1)<<2]; //记录延迟标记
void build(int node,int l,int r){
    addmark[node] = 0;
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
//将延迟标记向下传递
void pushdown(int node){
    if(addmark[node] != 0){
	//因为可能存在被多个延迟标记标记的情况，所以这里使用+=
        addmark[2*node] += addmark[node];
        addmark[2*node+1] += addmark[node];
	//当前节点的标记的意义是，当前节点的子节点需要更新标记记录的值，而和当前节点无关
	//所以在将当前节点的标记清零时，要将子节点的值更新标记记录的值，而上面两行是记录子节点的子节点需要更新的值
        segt[2*node] += addmark[node];
        segt[2*node+1] += addmark[node];
        addmark[node] = 0;
    }
}
int __query(int node,int qb,int qe,int nb,int ne){
    if(qb > ne || qe < nb) return INF;
    if(qb <= nb && ne <= qe) return segt[node];
    pushdown(node);
    int mid = nb+(ne-nb)/2;
    return min(__query(node*2,qb,qe,nb,mid),__query(node*2+1,qb,qe,mid+1,ne));
}
//更新单个值
void updateOne(int node,int index,int addval,int nb,int ne){
    if(nb == ne){
        segt[node] += addval;
        return;
    }
    int mid = nb+(ne-nb)/2;
    if(index <= mid) updateOne(node*2,index,addval,nb,mid);
    else             updateOne(node*2+1,index,addval,mid+1,ne);
    segt[node] = min(segt[node*2],segt[node*2+1]);
}
//更新一个区间的所有值
void updateInterval(int node,int ub,int ue,int addval,int nb,int ne){
    if(ub > ne || ue < nb) return;
    if(nb <= ub && ue <= ne) {
        addmark[node] += addval;
        segt[node] += addval;
        return;
    }
    pushdown(node); //先更新子节点，再往下递归更新
    int mid = nb+(ne-nb)/2;
    updateInterval(node,ub,mid,addval,nb,ne);
    updateInterval(node,mid+1,ue,addval,nb,ne);
    //此时可以保证子节点的值已经更新，然后再更新当前节点的值
    segt[node] = min(segt[2*node],segt[2*node+1]);
}
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
