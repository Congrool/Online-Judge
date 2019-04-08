#include<iostream>
#include<memory.h>
using namespace std;
int N;
int hang[14], lie[14], zhu[26], fu[26];
int numofcheese = 0;
int maxnum = 0;
//������һ��ʼ�뵽���㷨���ö���ѭ���ݹ�
//ʱ�临�Ӷ�ʵ��̫�� 
/*
void dfs(int cx,int cy) {
	if (numofcheese > maxnum) {
		maxnum = numofcheese;
	}
	for (int i = cx+1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			int ijzhu = i>j ? (N+j-i-1):(j+N-i);
			int ijfu = (i + j<N) ? i + (j - 1) : j + (i - 1);
			if (!hang[i] && !lie[j] && !zhu[ijzhu] && !fu[ijfu]) {
				hang[i] = 1, lie[j] = 1, zhu[ijzhu] = 1, fu[ijfu] = 1;
				numofcheese++;
				dfs(i,j);
				numofcheese--;
				hang[i] = 0, lie[j] = 0, zhu[ijzhu] = 0, fu[ijfu] = 0;
			}
		}
	return;
}*/
//���ǽ�������ϵؽ����������Ҫ�õ���һ����Ϣ����n���ʺ�϶�Ҫ���ڵ�n�У�����N�ʺ������޽�
//����ܰ�һ��ѭ��ʡ�Ե��� 
void dfs(int i) {
	if (i > N) {
		maxnum++;
		if (maxnum <= 3) {
			for (int i = 1; i <= N; i++)
				printf("%d ", hang[i]);
			cout << endl;
		}
		return;
	}
	for (int j = 1; j <= N; j++) {
		int ijzhu = i>j ? (N + j - i - 1) : (j + N - i);
		int ijfu = (i + j<N) ? i + (j - 1) : j + (i - 1);
		if (!lie[j] && !zhu[ijzhu] && !fu[ijfu]) {
			hang[i] = j;
			lie[j] = 1, zhu[ijzhu] = 1, fu[ijfu] = 1;
			dfs(i + 1);
			lie[j] = 0, zhu[ijzhu] = 0, fu[ijfu] = 0;
			hang[i] = 0;
		}
	}
}
int main() {
	while (cin >> N) {
		maxnum = 0;
		numofcheese = 0;
		memset(hang, 0, sizeof(hang));
		memset(lie, 0, sizeof(lie));
		memset(zhu, 0, sizeof(zhu));
		memset(fu, 0, sizeof(fu));
		dfs(1);
		cout << maxnum << endl;
	}
}
