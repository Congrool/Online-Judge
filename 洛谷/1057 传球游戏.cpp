/*
二维数组的递推问题
*/
#include<iostream>
#include<memory.h>
using namespace std;
int n,m;
int arr[31][31];
int main(){
	while(cin >> n >> m){
		memset(arr,0,sizeof(arr));
		arr[n][1] = 1;
		arr[2][1] = 1;
		for(int k = 2; k <= m; k++){
			arr[1][k] = arr[2][k-1]+arr[n][k-1];
			for(int i = 2; i < n; i++)
				arr[i][k] = arr[i-1][k-1] + arr[i+1][k-1];
			arr[n][k] = arr[n-1][k-1] + arr[1][k-1];
		}
		cout << arr[1][m] << endl;
	}
}