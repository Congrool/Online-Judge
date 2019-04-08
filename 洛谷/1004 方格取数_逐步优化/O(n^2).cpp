//空间复杂度O(n^2)
//倒推
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
int dp[10][10];
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
int main(){
    n = readnum();
    int xi,yi,wi;
    xi = readnum(),yi = readnum(), wi = readnum();
    while( xi != 0 && yi != 0 && wi != 0){
        mat[xi][yi] = wi;
        xi = readnum(),yi = readnum(), wi = readnum();
    }
    for(int s = 2; s <= 2*n; s++)
        for(int i = n; i >= 1; i--)
            for(int k = n; k >= 1; k--){
                int j = s-i,l = s-k;
                if(j < 1 || l < 1) continue;
                dp[i][k] = max(dp[i-1][k],max(dp[i][k-1],max(dp[i][k],dp[i-1][k-1])));
                if(i == k && j == l)
                    dp[i][k] += mat[i][j];
                else{
                    dp[i][k] += mat[i][j] + mat[k][l];
                }
            }
    cout << dp[n][n] << endl;
}