#include<iostream>
using namespace std;
typedef long long ll;
ll ksm(ll x,ll n){
    ll ans = 1, base = x;
    while(n){
        if(n&1){
            ans *= base;
        }
        base *= base;
        n >>= 1;
    }
    return ans;
}
int main(){
    ll a,n;
    cin >> a >> n;
    cout << ksm(a,n) << endl;
}