//维护不同运算的线段树
//这里是乘法和加法
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN = 100010;
ll tagadd[MAXN<<2],segt[MAXN<<2],tagmul[MAXN<<2];
ll arr[MAXN];
int M,N;
ll P;
inline void push_up(int p){
    segt[p] = (segt[p<<1] + segt[(p<<1)|1])%P;
}
void build(int p,int b,int e){
    tagmul[p] = 1;
    if(b == e){
        segt[p] = arr[b];
        return;
    }
    int mid = (b+e)>>1;
    build(p<<1,b,mid);
    build((p<<1)|1,mid+1,e);
    push_up(p);
}

//核心代码
//在push_down的时候，子节点的addtag值是父节点addtag值乘以父节点multag值
inline void push_down(int p,int b,int e){
    int mid = (b+e)>>1;
    segt[p<<1] = (segt[p<<1]*tagmul[p]+tagadd[p]*(mid-b+1))%P;
    segt[(p<<1)|1] = (segt[(p<<1)|1]*tagmul[p]+tagadd[p]*(e-mid))%P;
    
    tagmul[p<<1] = (tagmul[p<<1]*tagmul[p])%P;
    tagmul[(p<<1)|1] = (tagmul[(p<<1)|1]*tagmul[p])%P;
    tagadd[p<<1] = (tagadd[p<<1]*tagmul[p]+tagadd[p])%P;
    tagadd[(p<<1)|1] = (tagadd[(p<<1)|1]*tagmul[p]+tagadd[p])%P;

    tagmul[p] = 1;
    tagadd[p] = 0;
}
void add_value(int p,int b,int e,int l,int r,ll addv){
    if(b>r || e<l) return;
    if(l <= b && e <= r){
        tagadd[p] = (tagadd[p]+addv)%P;
        segt[p] = (segt[p]+(e-b+1)*addv)%P;
        return;
    }
    push_down(p,b,e);
    int mid = (b+e)>>1;
    if(l <= mid) 
        add_value(p<<1,b,mid,l,r,addv);
    if(mid < r) 
        add_value((p<<1)|1,mid+1,e,l,r,addv);
    push_up(p);
}
void mul_value(int p,int b,int e,int l,int r,ll mulv){
    if(b>r || e<l) return;
    if(l <= b && e <= r){
        segt[p] = (segt[p]*mulv)%P;
        tagmul[p] = (tagmul[p]*mulv)%P;
        tagadd[p] = (tagadd[p]*mulv)%P;
        return;
    } 
    push_down(p,b,e);
    int mid = (b+e)>>1;
    if(l <= mid) 
        mul_value(p<<1,b,mid,l,r,mulv);
    if(mid < r) 
        mul_value((p<<1)|1,mid+1,e,l,r,mulv);
    push_up(p);
}
ll query(int p,int b,int e,int l,int r){
    if(b>r || e<l) return 0;
    ll res = 0;
    if(l <= b && e <= r) return segt[p];
    push_down(p,b,e);
    int mid = (b+e)>>1;
    if(l <= mid) 
        res = (res+query(p<<1,b,mid,l,r))%P;
    if(mid < r) 
        res = (res+query((p<<1)|1,mid+1,e,l,r))%P;
    return res;
}
ll readnum(){
    ll ans = 0,sign = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') sign = -1; ch = getchar();}
    while('0' <= ch && ch <= '9') {ans = ans*10 + ch-'0'; ch = getchar();}
    return ans*sign;
}
int main(){
    scanf("%d%d%lld",&N,&M,&P);
    for(int i = 1; i <= N; i++){
        arr[i] = readnum();
    }
    build(1,1,N);
    int o,x,y;
    ll k;
    while(M--){
        scanf("%d",&o);
        if(o == 1){
            scanf("%d%d%lld",&x,&y,&k);
            mul_value(1,1,N,x,y,k);
        }
        else if(o == 2){
            scanf("%d%d%lld",&x,&y,&k);
            add_value(1,1,N,x,y,k);
        }
        else{
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,1,N,x,y));
        }
    }
}