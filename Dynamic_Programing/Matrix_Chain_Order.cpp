#include<iostream>
#include<climits>
using namespace std;
const int Length = 4;
int m[Length + 1][Length + 1];
int s[Length + 1][Length + 1];
void Marix_chain_order(int p[])
{

	for (int i = 1; i <= Length; i++)
		m[i][i] = 0;
	for (int chain_len = 2; chain_len <= Length; chain_len++)
		for (int i = 1; i <= Length - chain_len + 1; i++)	 //计算1+chain_length，2+chain_length...
                                                       //即遍历数组中所有链长为chain_length的子链
		{
			int j = i + chain_len - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)            //遍历矩阵链(i,j)子链中所有划分k,找到最小乘法数量
                                                  //即矩阵链(i,j)段的最优划分
                                                  //并记录乘法数量到m数列，记录划分k到s数列
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
}
int main()
{
	int p[Length + 1];
	for (int i = 0; i < Length+1; i++)
		cin >> p[i];
	Marix_chain_order(p);
	cout << m[1][Length] << endl;
}
