/*
递推问题，未优化
*/
#include<iostream>
#include<memory.h>
using namespace std;
int n,k;
int count;
int arr[7];
void dp(int ls,int be){
	if(ls == k-1){
		arr[ls+1] = n-be+1;
		if(arr[ls+1] < arr[ls])
			return;
		count++;
		return;
	}
	if(ls != 1 && arr[ls-1] > arr[ls])
		return;
	for(int i = be; i < n; i++){
		arr[ls] = (i-be)+1;
		dp(ls+1,i+1);
		arr[ls] = 0;
		}	
}
int main(){
	while(cin >> n >> k){
		memset(arr,0,sizeof(arr));
		count = 0;
		dp(1,1);
		cout << count << endl;
	}
}