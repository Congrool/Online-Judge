#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN = 10007;
int p[MAXN+1],vis[MAXN+1],phi[MAXN+1];
int len = 0;
void get_prime(){
    phi[1] = 1;
    for(int i = 2; i <= MAXN; i++){
        if(!vis[i]){
            p[len++] = i;
            phi[i] = i-1;
        }
        for(int j = 0; j < len && i*p[j] <= MAXN; j++){
            vis[i*p[j]] = 1;
            if(i % p[j] == 0){
                phi[i*p[j]] = phi[i]*p[j];
                break;
            }
            else{
                phi[i*p[j]] = phi[i]*(p[j]-1);
            }
        }
    }
}
int main(){
    get_prime();
}