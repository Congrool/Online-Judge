#include<iostream>
class union_find{
	private:
		static const int MAX_N = 1000001;
		int par[MAX_N];	//父亲 
		int rank[MAX_N]; //树的高度 
	public:
		union_find(){
		}
		void init(int n){
			for(int i = 0; i < n; i++){
				par[i] = i;
				rank[i] = 0;
			}
		}
		//查询树的根 
		int find(int x){
			if(par[x] == x)
				return x;
			else
				return par[x] = find(par[x]); //返回的同时压缩路径 
		}
		void unite(int x,int y){
			x = find(x);
			y = find(y);
			if(x == y) return;
			if(rank[x] < rank[y]){
				par[x] = y;
			}else{
				par[y] = x;
				if(rank[x] == rank[y]) //处理两棵树树高相等的情况，
									   //当树高相等时，因为已经将y合并到x上，所以x的树高就要增加
					rank[x]++;
			}
		}
		bool same(int x,int y){
			return find(x) == find(y);
		} 
};
int main(){
	
}