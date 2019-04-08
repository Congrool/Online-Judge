/*奶牛吃草
有N片草地，每片草地上的草量为wi。草地间存在若干条路径。现奶牛从1号节点出发，通过路径到达其他草地，且每条路径只能通过一次。当没有可以到达的草地或是能够到达的草地都已经被吃光之后，奶牛就会回家。问奶牛通过最优的路径能够吃到的最大草量为多少。

第1行输入两个正整数N(N<=100)和M(M<=2000)， 表示草地的数量和草地间路径的数量。
第2行输入N个正整数，第i个整数表示第i个草地的草量w[i]。
第3行至第M+2行，每行输入两个正整数u和v，表示存在一条从u到v的单向路径。
输出一个整数，即奶牛最多能够吃到的草量。
*/
#include<iostream>
#include<string.h>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<memory.h>
using namespace std;
int N, M;
int val[101];
int dp[101];
int used[101];
vector<int> Vex;
vector<int> G1[101];
vector<int> G2[101];
int rec[101][101];
void dfs(int s) {
	for (int i = 0; i < G2[s].size(); i++) {
		int v = G2[s][i];
		if (rec[s][v])
			continue;
		int nval;
		int sign = 0;
		if (!used[v]) {
			used[v] = 1;
			sign = 1;
			rec[s][v] = 1;
			nval = val[v] + dp[s];
		}
		else {
			nval = dp[s];
		}
		dp[v] = max(dp[v], nval);
		dfs(v);
		if (sign == 1) {
			used[v] = 0;
			rec[s][v] = 0;
		}
	}
}
int main() {
	while (cin >> N >> M) {
		for (int i = 1; i <= N; i++)
			cin >> val[i];
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			G1[u].push_back(v);
			G2[v].push_back(u);
		}
		//找到原图中出度为0的顶点，存在Vex中 
		for (int i = 1; i <= N; i++) {
			if (G1[i].size() == 0) {
				dp[i] = val[i];
				Vex.push_back(i);
			}
		}

		//深度优先遍历Vex中的顶点 
		for (int i = 0; i < Vex.size(); i++) {
			dfs(Vex[i]);
		}
		cout << dp[1] << endl;
	}

}
