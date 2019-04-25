//成段增减区间求和线段树模板
#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll MAXN = 100010;
ll arr[MAXN];
ll segt[MAXN<<2],tag[MAXN<<2];
ll N,Q;
inline void push_up(ll p){
//求和
    segt[p] = segt[p<<1]+segt[(p<<1)|1];
}
void build(ll p,ll b,ll e){
    tag[p] = 0;
    if(b == e){
        segt[p] = arr[b];
        return;
    }
    ll mid = (b+e)>>1;
    build(p<<1,b,mid);
    build((p<<1)|1,mid+1,e);
    push_up(p);
}
void push_down(ll p,ll b,ll e){
    if(tag[p] == 0) return;
    ll mid = (b+e)>>1;
    segt[p<<1] += tag[p]*(mid-b+1);
    tag[p<<1] += tag[p];
    segt[(p<<1)|1] += tag[p]*(e-mid);
    tag[(p<<1)|1] += tag[p];
    tag[p] = 0;
}
void update(ll l,ll r,ll b,ll e,ll p,ll k){
    if(l <= b && e <= r){
        tag[p] += k;		  //表示当前节点的子节点需要更新
        segt[p] += (k*(e-b+1));　　｀//[b,e]的每一个元素都加k，所以节点就要加上k*(e-b+1)
        return;
    }
    push_down(p,b,e);
    ll mid = (b+e) >> 1;
    if(l <= mid) update(l,r,b,mid,p<<1,k);
    if(mid < r) update(l,r,mid+1,e,(p<<1)|1,k);
    push_up(p);
}
ll query(ll l,ll r,ll b,ll e,ll p){
    ll res = 0;
	//查询区间在当前节点区间内，则返回当前节点的值
    if(l <= b && e <= r) return segt[p];
    push_down(p,b,e);
    ll mid = (b+e)>>1;
    if(l <= mid) res += query(l,r,b,mid,p<<1);
    if(mid < r) res += query(l,r,mid+1,e,(p<<1)|1);
    return res;
}
