#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string pre, post, in;
int posofin(char pstch,string& in) {
	for (int i = 0; i < in.length(); i++)
		if (in[i] == pstch)
			return i;
	return -1;
}
//举例中序遍历 ECFBDGAIJH
//	  后序遍历 EFCGDBJIHA
//step找出后序遍历最后一个元素A，查找它在中序遍历中的位置inpos 
//以inpos将中序遍历划分成两个子问题的中序遍历nlin = "ECFBDG" 和 nrin = "IJH"
//将后序遍历也划分成两个子问题的后序遍历nlpost = "EFCGDB" 和 nrpost = ""JIH"
//得到两个子问题nlin = "ECFBDG"      nrin = "IJH"
//				nlpost = "EFCGDB"    nrpost = "JIH"
//递归求解
//关键是递归的思想，必须明确子问题，否则不可能写出递归 
void solve(string post,string in) {
	if (post.length() == 0||in.length() == 0) {
		return;
	}
	cout << post[post.length()-1];
	int inpos = posofin(post[post.length() - 1],in);
	string nlin, nrin;
	string nlpost, nrpost;
	nlin.append(in, 0, inpos);
	nrin.append(in, inpos+1, in.length() - inpos -1);
	nlpost.append(post, 0, inpos);
	nrpost.append(post, inpos, in.length() - inpos - 1);
	solve(nlpost, nlin);
	solve(nrpost, nrin);
}
int main() {
	while (cin >> in >> post) {
		solve(post, in);
	}
}
