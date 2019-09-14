# 字典树（Trie树）

主要用于：

+ 查找有相同前缀字符串的字符串的数目    O(n)   n为前缀字符串的长度

数据结构的操作：

+ 插入   O(n) n为要插入的字符串的长度
+ 查找   O(n) n为要查找的字符串的长度



其缺陷在于空间复杂度相当高，为O(n*S)

其中n为字符串的平均长度，S为字符集的大小。



字典树的性质：

1. 根节点不包含字符，其余每个节点都包含一个字符。
2. 从根节点到某一节点，其经过的路径节点就是该节点对应的字符串。
3. 每个节点的所有子节点包含的字符都不相同，是一整个字符集



节点的结构：

```c++
struct tn {
	bool isword;            // 是否是单词
	int next[CHARSETSIZE];	// 子节点的索引
	int cnt;                // 记录以当前字符路径作为前缀的字符串的个数
	tn(char _ch = 0, bool _isword = false, int _cnt = 0) :isword(_isword), cnt(_cnt){
		memset(next, 0, sizeof(next));
	}
};
```



附上自己写的Trie树代码：

```c++
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int CHARSETSIZE = 26; // 字符集为26个小写字母
struct tn {
	bool isword;            // 是否是字符串，因为节点可能只是字符串中的一个字符
	int next[CHARSETSIZE];
	int cnt;                // 记录以当前字符路径作为前缀的字符串的个数
	tn(char _ch = 0, bool _isword = false, int _cnt = 0) :isword(_isword), cnt(_cnt){
		memset(next, 0, sizeof(next));
	}
};
vector<tn> trie;
inline void insert(const string &s) {
	int len = s.length();
	// tn &cur = trie[0];   神秘bug 无力解决 暂且换一种写法
	int cur = 0;
	for (int i = 0; i < len; i++) {
		int p = s[i] - 'a';
		if (trie[cur].next[p] == 0) {
			tn tmp(s[i], false, 0);
			trie[cur].next[p] = trie.size();
			trie.push_back(tmp);
		}
		trie[cur].cnt += 1;
		cur = trie[cur].next[p];
	}
	trie[cur].isword = true;
	trie[cur].cnt++;
}
inline int search(const string &s) {
	int len = s.length();
	// tn &cur = trie[0];  同上的bug
    int cur = 0;
	for (int i = 0; i < len; i++) {
		int p = s[i] - 'a';
		if (trie[cur].next[p] == 0) return 0;
		cur = trie[cur].next[p];
	}
	return cur==0?0:trie[cur].cnt;
}
```

一些说明：

1. 由于malloc花费时间，所以使用vector，相当于一个静态数组使用
2. 父节点到字节点的指针使用数组索引代替