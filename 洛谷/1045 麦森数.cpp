//快速幂和高精度乘法的应用
#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int res[1001],ans[1001],base[1001];
int p;
//这里，ans，base 和 res中位权值从左到右递增 
void multi1(){
	memset(res,0,sizeof(res));
	for(int i = 1; i <= 500; i++)
		for(int j = 1; j <= 500; j++)
			res[i+j-1] += ans[i]*base[j];
	for(int i = 1; i <= 500; i++){
		res[i+1] += res[i]/10;
		res[i] %= 10;
	}
}
void multi2(){
	memset(res,0,sizeof(res));
	for(int i = 1; i <= 500; i++)
		for(int j = 1; j <= 500; j++)
			res[i+j-1] += base[i]*base[j];
	for(int i = 1; i <= 500; i++){
		res[i+1] += res[i]/10;
		res[i] %= 10;
	}
}
void ksm(){
	memset(base,0,sizeof(base));
	memset(ans,0,sizeof(ans));
	base[1] = 2;
	ans[1] = 1;	
	while(p){
		if(p&1){
			multi1();
			memcpy(ans,res,sizeof(res));
		}
		multi2();
		memcpy(base,res,sizeof(res));
		p>>=1;
	}
}
int main(){
	while(cin >> p){
		printf("%d\n",(int)(log10(2)*p+1));
		ksm();
		ans[1] -= 1;
		for(int i = 500; i >=1; i--){
			if(i != 500 && i%50 == 0)
				printf("\n%d",ans[i]);
			else
				printf("%d",ans[i]);
		}
		cout << endl;		
	}
}
