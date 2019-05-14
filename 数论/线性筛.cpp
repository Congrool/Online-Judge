#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN = 10007;
int p[MAXN+1],vis[MAXN+1];
int len = 0;
void get_prime(){
    for(int i = 2; i <= MAXN; i++){
        if(!vis[i])
            p[len++] = i;
        for(int j = 0; j < len && i*p[j] <= MAXN; j++){
            vis[i*p[j]] = 1;
            if(i % p[j] == 0) break; //这是一个优化，基于以下原则：
        }							 //每个合数都被它最小的质因数筛出
    }							 	 //很好的实现了每个数都只筛一次的思想
}
int main(){
    get_prime();
}