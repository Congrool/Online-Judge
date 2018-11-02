/*
设有 N 堆石子，其编号为 1, 2, 3, …, N。每堆石子有一定的数量。
现要将 N 堆石子并成为一堆。每次合并只能将相邻的两堆堆在一起（每次合并花费的体力为当前两堆石子的数量总和），
这样经过 N - 1 次合并后成为一堆，归并的总体力为每次合并花费的体力和。
找出一种合理的合并方法，使所花费的总的体力最小。
*/
//直接联想到矩阵链乘的问题的求解方法

#include<iostream>
#include<memory.h>
#include<climits>
using namespace std;
int N;
int arr[651];       //记录石子数量
int sum[651][651];  //动态规划数组，记录i到j最小体力消耗
int preisum[651];  //记录arr前i项的和
//递归，超时。。
/*
int dp(int i,int j)
{
	if(sum[i][j] != -1)
		return sum[i][j];
	int res = INT_MAX;
	for(int k = i; k < j; k++)
		res = min(res,dp(i,k)+dp(k+1,j));
	res += preisum[j] - preisum[i-1];	
	if(sum[i][j] == -1)
		sum[i][j] = res;
	return res;
	
}
*/
//递推，能过
void dp(int i,int j)
{
	for(int i = 0; i <= N; i++)
		sum[i][i] = 0;
	for(int len = 2; len <= N; len++){
		for(int i = 1; i+len-1 <= N; i++){
			int j = i+len-1;
			sum[i][j] = INT_MAX;
			for(int k = i; k < j; k++){
				int q = sum[i][k] + sum[k+1][j] + preisum[j]-preisum[i-1];
				if(q < sum[i][j])
					sum[i][j] = q;
			}	
		}
	}
}
int main()
{
	while(cin >> N)
	{
		memset(preisum,0,sizeof(preisum));
		memset(arr,0,sizeof(arr));
	  /*
    //递归方法需要的代码
    for(int i = 0; i <= N; i++)
			for(int j = 0; j <= N; j++)
				sum[i][j] = -1;   
		for(int i = 0; i <= N; i++)
			sum[i][i] = 0;
    */
		for(int i = 1; i <= N; i++)
			cin >> arr[i];
		for(int i = 1; i <= N; i++)
			preisum[i] = preisum[i-1]+arr[i];		
	  //递归的输出
    //cout << dp(1,N)<< endl;
    dp(1,N);
    cout << sum[1][N] << endl;
	}
 } 
