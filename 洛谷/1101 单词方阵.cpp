#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<vector>
using namespace std;
char rec[101][101];
char res[101][101];
const string aim = "yizhong";
const int xx[8] = { 1,-1,0,0,1,-1,1,-1 };
const int yy[8] = { 0,0,1,-1,1,-1,-1,1 };
int n;
char read() {
	char ch = getchar();
	while (isspace(ch)) {
		ch = getchar();
	}
	return ch;
}
void solve(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x, ny = y;
		int j = 1;
		for (; j < aim.length(); j++) {
			nx += xx[i], ny += yy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && rec[nx][ny] == aim[j]) {
				continue;
			}
			else
				break;
		}
		if (j != aim.length()) continue;
		nx = x, ny = y;
		res[x][y] = 'y';
		for (int j = 1; j < aim.length(); j++) {
			nx += xx[i], ny += yy[i];
			res[nx][ny] = aim[j];
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res[i][j] = '*';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char tmp = read();
			rec[i][j] = tmp;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (rec[i][j] == 'y') {
				solve(i, j);
			}
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j];
		}
		cout << endl;
	}
}