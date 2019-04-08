/*离散化*/
#include<iostream>
#include<set>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
int N;
ll st[20010],te[20010],rec[40010];
bool flag[40010];
int main(){
	while(cin >> N){
		int m = 0;
		for(int i = 0; i < N; i++){
			ll s,t;
			scanf("%d%d",&s,&t);
			st[i] = s, te[i] = t;
			rec[m++] = s, rec[m++] = t;
		}
		sort(rec,rec+N);
		for(int i = 0; i < N; i++){
			int spos = lower_bound(rec,rec+N,st[i])-rec;
			int tpos = lower_bound(rec,rec+N,te[i])-rec;
			for(int j = spos+1; j <= tpos ;j++){
				flag[j] = 1;
			}
		}
		
		ll res = 0;
		for(int i = 0; i < N; i++){
			if(flag[i]){
				res += rec[i]-rec[i-1];
			}
		}
		cout << res << endl;
	}
}