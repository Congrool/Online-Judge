#include<iostream>
using namespace std;
int arr[101][101];
int rec[101][101][101];
/*
rec[i][j][k]记录arr[i][j]的所有余数
每次计算只要找它前一个的余数与arr[i][j]相乘%K求模保存在rec[i][j]中
没啥好多说的
*/
int M, N, K;
int main() {
	while (cin >> M >> N >> K) {
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		int yu00 = arr[0][0] % K;
		rec[0][0][yu00] = 1;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++) {
				int px1 = i - 1, py1 = j;
				int px2 = i, py2 = j - 1;
				if (0 <= px1 && px1 < M && 0 <= py1 && py1 < N) {
					for (int k = 0; k < K; k++) {
						if (rec[px1][py1][k]) {
							int yu = (k * arr[i][j]) % K;
							rec[i][j][yu] = 1;
						}
					}
				}
				if (0 <= px2 && px2 < M && 0 <= py2 && py2 < N) {
					for (int k = 0; k < K; k++) {
						if (rec[px2][py2][k]) {
							int yu = (k * arr[i][j]) % K;
							rec[i][j][yu] = 1;
						}
					}
				}
			}
		int sum = 0;
		for (int i = 0; i<K; i++)
			if (rec[M - 1][N - 1][i])
				sum++;
		cout << sum << endl;
		for (int i = 0; i < K; i++)
			if (rec[M - 1][N - 1][i])
				cout << i << " ";
	}
}