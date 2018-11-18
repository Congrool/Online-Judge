/*
  欧几里德的两个后代Stan和Ollie正在玩一种数字游戏，这个游戏是他们的祖先欧几里德发明的。
  给定两个正整数M和N，从Stan开始，从其中较大的一个数，减去较小的数的正整数倍，
  当然，得到的数不能小于0。然后是Ollie，对刚才得到的数，和M，N中较小的那个数，
  再进行同样的操作……直到一个人得到了0，他就取得了胜利
 */
 
 //主要思路：
 /*
    假定N > M
    分成三种情况：
    1. N%M == 0 则当前的人直接获胜
    2. N - M < M, 则因为只能减去M，没有选择的余地，所以当(N-M,M)必败时，（N,M)必胜，反之同理
    3. N - M > M, 考虑N - MX > M,  N-M(X-1) < M , (N-M(X-1), M) 只能减去M
                   1.若（N-MX,M)必胜，则（N-M(X-1),M) 必败，（N,M)必胜
                   2.若 （N-MX,M) 必败，则(N-M(X-1),M)必胜，(N,M)必败；但当前操作的人可以避免这种情况，将(N-MX,M)的必败态留给对手
      所以 N— M > M 必胜
  */
#include<iostream>
using namespace std;
int C;
int main()
{
	cin >> C;
	int num = 0;
	while(num++ < C)
	{
		int M,N;
		cin >> M >> N;
		bool sign = true;
		while(true){
			if(M > N){
				int t = N;
				N = M;
				M = t;
			}
			if(N%M == 0 || N-M > M)
				break;
			else{
				M = N-M;
				sign = !sign;
			}
		}
		if(sign)	cout << "Stan wins" << endl;
		else
			cout << "Ollie wins"<< endl;
	}		 
 } 
