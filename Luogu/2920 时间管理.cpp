//AOE网的思路
//设当前事件为a[i]
//按结束时间从大到小的顺序模拟
//init: ans = a[1].end
//if ans <= a[i].end: ans -= a[i].last
//else ans = a[i].end - a[i].last
#include<iostream>
#include<algorithm>
using namespace std;
int m,n;
struct node{
	int l,e;
};
bool cmp(const node& n1, const node &n2){
	return n1.e>n2.e;
} 
node rec[1001];
int main(){
	cin >> n;
	for(int i = 1; i<=n; i++){
		scanf("%d %d",&rec[i].l,&rec[i].e);
	}
	sort(rec+1,rec+n+1,cmp);
	int res = rec[1].e;
	for(int i = 1; i <=n ;i++){
		if(res <= rec[i].e)
			res -= rec[i].l;
		else
			res = rec[i].e-rec[i].l;
	}
	res = res<0 ? -1 : res;
	cout << res << endl;
	
}