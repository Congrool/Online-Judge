/*
手写全排列
*/
#include<iostream>
#include<algorithm>     //c++自带全排列函数 next_permutation(array,array+n)
using namespace std;
const int MAX = 3;
bool used[MAX];
int perm[MAX];
int count1 = 0;
void permutation1(int pos, int n)
{
	if (pos == n)
	{
		for (int i = 0; i < MAX; i++)
			printf("%d", perm[i]);
		printf("\n");
		count1++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!used[i]) {
			perm[pos] = i+1;
			used[i] = true;
			permutation1(pos + 1, n);
			used[i] = false;
		}
	}
	return;
}
int main()
{
	for (int i = 0; i<MAX; i++)
		used[i] = false;
	permutation1(0, 3);
	cout << endl;
	cout << count1 << endl;
}
