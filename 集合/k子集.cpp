/*
lotto:
列举有n个元素的集合的所有大小为k的子集，并按升序输出
*/
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int main(){
	int n;
	while(cin >> n)
	{
		int arr[n+1];	
		for(int i = 1; i <= n; i++)
			 cin >> arr[i];
		sort(arr+1,arr+n+1);
		int k = 6;
		int comb = (1 << k)-1;		//最小的即00111111开始
		stack<int> med;
		//核心代码begin
		while(comb < 1 << n){
			med.push(comb);
			int x = comb & -comb;		//求得最低位的1
			int y = comb + x;			//将1区间置零，并将左侧第一个0置1
			comb = ((comb & ~y) / x >> 1 ) | y;  // 左侧将连续的1区间右移直到缺少一个1
		}
		//核心代码end
		/*
		核心代码注释
		该循环列举了所有大小为k（本题为6）的子集，
		但它是以comb二进制为基础的升序，例如
		00111111
		01011111
		01101111
		01110111
		······
		11111100
		求comb的下一个二进制的四步：
		1.求出最低位的1开始的连续的1区间
		2.将1区间全部置零，并将区间左侧的第一个0变为1
		3.将步骤1求得的1区间右移，直到少了一个1
		4.将2、3两步的区间进行或运算
		*/
		stack<int> temp;
		while(!med.empty()){
			int cur = med.top();
			med.pop();
			int poi = n;
			while(cur){
				if(cur%2) temp.push(arr[poi]);
				poi--;
				cur/=2;
			}
			int num = temp.size();
			while(num-- >1){
				cout << temp.top()<< " ";
				temp.pop();
			}
			cout << temp.top();
			temp.pop();
			cout << endl;
		}
	}
} 
