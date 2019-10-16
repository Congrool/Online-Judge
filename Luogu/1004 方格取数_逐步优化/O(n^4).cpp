#include<iostream>
#include<memory.h>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
const int INT_INF = 0x3f3f3f3f;
const long long ll_INF = 0x3f3f3f3f3f3f3f3f;
typedef long long ll;
typedef pair<char,int> PCI;
int n,mat[10][10];
int dp[10][10][10][10];
int readnum(){
    char ch = getchar();
    int ans = 0;
    while(ch < '0' || ch > '9') ch = getchar();
    while('0' <= ch && ch <= '9'){
        ans = ans*10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
void solve(){

}
int main(){
    n = readnum();
    int xi,yi,wi;
    xi = readnum(),yi = readnum(), wi = readnum();
    while( xi != 0 && yi != 0 && wi != 0){
        mat[xi][yi] = wi;
        xi = readnum(),yi = readnum(), wi = readnum();
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++){
                int l = i+j-k;
                if(l < 1) continue;
                dp[i][j][k][l] = max(dp[i-1][j][k-1][l],max(dp[i-1][j][k][l-1],max(dp[i][j-1][k][l-1],dp[i][j-1][k-1][l])));
                if(i == k && j == l)
                    dp[i][j][k][l] += mat[i][j];
                else{
                    dp[i][j][k][l] += mat[i][j]+mat[k][l];
                }
            }
    cout << dp[n][n][n][n] << endl;
}