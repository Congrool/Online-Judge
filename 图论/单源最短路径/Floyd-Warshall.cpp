//Floyd_Warshall算法
//DP求解思路：
//只使用顶点0~k和i，j的情况，记i到j的最短路长为d[k+1][i][j],
//将使用顶点0~k归约到顶点0~k-1上
//讨论两种情况，即最短路径是否经过k点
//1.经过k点，且肯定只有一次：d[k][i][j] = d[k-1][i][k]+d[k-1][k][j]
//2.不经过k点：d[k][i][j] = d[k-1][i][j] 
//再优化一下空间，因为只用到了上一层的信息，所以用滚动数组的实现方式d[2][MAX_V][MAX_V}
//还能再优化一下，因为每次循环都保存了上次的信息，所以d[MAX_V][MAX_V] 
//O(|V|^3)
//特点：写起来简单
//判断图中是否存在负圈，只需检查是否存在d[i][i]为负数的i就行了 
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_V = 100;
const int MAX_E = 100;
int V,E;
int d[MAX_V][MAX_E]; //d[u][v]表示了e=(u,v)的权值 
void floyd_warshall(){
	for(int k = 0; k < V; k++)
		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++){
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
}
int main(){
	
} 