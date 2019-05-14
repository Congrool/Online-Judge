#include<algorithm>
#include<iostream>
#include<ctime>
using namespace std;
const int MAXN = 1000;
int trarr[MAXN+1],arr[MAXN+1];
//返回最后一位1的位置
inline int lowbit(int n){
    return n&(-n);
}
//求[1,r]区间的和
int getsum(int r){
    int sum = 0;
    for(int i = r; i > 0; i -= lowbit(i))
        sum += trarr[i];
    return sum;
}
//原数组arr[i]的值增加了val时，更新trarr数组，其实是求和过程的逆过程
void add(int p,int val){
    for(int i = p; i <= MAXN; i += lowbit(i))
        trarr[i] += val;
}
int main(){
    srand(time(NULL));
    for(int i = 1; i <= MAXN; i++){
        arr[i] = rand()%500;
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= MAXN; i++){
        add(i,arr[i]);
    }
    int T;
    cin >> T;
    while(T--){
        int l,r;
        cin >> l >> r;
        cout << getsum(r)-getsum(l-1) << endl;
        int sum = 0;
        for(int i = l; i <= r; i++){
            sum += arr[i];
        }
        cout << sum << endl;
    }
}