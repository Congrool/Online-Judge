#include<algorithm>
#include<iostream>
#include<cmath>
#include<set>
#include<cstring>
#include<string>
#include<cctype>
#include<memory.h>
#include<queue>
#include<climits>
#include<cstdlib>
#include<cassert>
#include<ctime>
using LL = long long;
//主要代码
const int MAXN = 1000;
struct RMQ{
    int f[MAXN][32];
    inline int highbit(int x){return 31-__builtin_clz(x);}
    void init(int *v,int n){
        for(int i = 0; i < n; i++) f[i][0] = v[i];
        int len = highbit(n);
        for(int j = 1; j < len; j++){
            int t = n-(1<<j)+1;
            for(int i = 0; i < t; i++)
                f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    int getmin(int l,int r){
        assert(l <= r);
        int p = highbit(r-l+1);
        return min(f[l][p],f[r-(1<<p)+1][p]);
    }
};

//测试
int main(){
    srand(time(0));
    int arr[MAXN];
    for(int i = 0; i < MAXN; i++){
        arr[i] = rand()%100007;
    }
    RMQ rec;
    rec.init(arr,MAXN);
    int T;
    cin >> T;
    for(int i = 0; i < MAXN; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    while(T--){
        int x,y;
        cin >> x >> y;
        cout << rec.getmin(x,y) << endl;
    }
}