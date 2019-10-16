/*离散化加树状数组*/
/*只能解决不重复数列*/
#include<iostream>
#include<set>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
typedef struct num {
	ll data;
	int raw_ord;
}num_type;
bool cmp(const num &num1, const num &num2) {
	return num1.data > num2.data;
}
int n;
num_type rec[500010];
int lsh[500010];
int cc[500010];
/*快读，比scanf快*/
ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch >'9') { if (ch == '-') f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x*f;
}
inline int Sum(int i) {
	int s = 0;
	while (i > 0) {
		s += cc[i];
		i -= i & -i;
	}
	return s;
}
inline void Add(int i, int x) {
	while (i <= n) {
		cc[i] += x;
		i += i & -i;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		rec[i].data = read();
		rec[i].raw_ord = i;
	}
	//离散化 
	sort(rec + 1, rec + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		lsh[rec[i].raw_ord] = i;
	}

	//树状数组求解 
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		Add(lsh[i], 1);
		ans += Sum(lsh[i] - 1);
	}
	cout << ans << endl;
}