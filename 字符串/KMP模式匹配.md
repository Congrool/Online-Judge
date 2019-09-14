# KMP模式匹配

## 特点

用于单模式匹配可以获得较快的效率



## 时间复杂度

预处理的时间复杂度：
$$
O(m)
$$
其中m是模式串的长度。



查找一次的时间复杂度：
$$
O(n+m)
$$
其中n是待查找字符串的长度，m是模式串的长度。



## 主要思想

在暴力的基础上，使用一个next数组，使得在字符串失配时，不需要回退待查找字符串中的指针，而只需要从next数组中找到一个新的索引赋给模式串中的指针，然后继续匹配。

其中找到的新索引满足以下条件（也是预处理next数组时需要满足的）：

设当前已匹配的字符串为$S_sS_{s+1}S_{s+2}...S_{s+k}和P_0P_1...P_{k}​$（$S​$为待查找字符串，$P​$为模式串），即已知
$$
S_sS_{s+1}S_{s+2}...S_{s+k} == P_0P_1...P_{k}
$$
而当前字符$S_{s+k+1} != P_{k+1}$。此时发生失配，需要找到一个新的索引$k'$来更新$k$。其中$k'$满足：
$$
k' = max\left\{k':S_{s+k-k'}...S_{s+k-1}S_{s+k} == P_0P_1...P_{k'}\right\} \quad\quad(1)
$$
即满足$P_0P_1...P_{k'}​$是$S_sS_{s+1}S_{s+2}...S_{s+k}​$后缀且是模式串$P​$中的最大前缀字符串。





## 算法流程

### 预处理next数组

```pseudocode
COMPUTE-PREFIX-FUNCTION(P)
	next[1] = 0
	k = 0
	for i=2 to P.length
		while k > 0 and P[i] != P[k+1]	//往前找满足(1)的k值，直到k=0或者P[k+1] == P[i]
			k = next[k]
		if P[i] == P[k+1]				//查看新的k值是否可以匹配，即满足P[k+1] == P[i]
			k = k+1						//满足就是K=K+1，当下次以P[i]*结尾失配时可以跳转到这里
		next[i] = k
```

其实是对自己进行一遍模式匹配，可以发现COMPUTE-PERFIX-FUNCTION的流程和KMP的流程很相似。



### KMP模式匹配

```pseudocode
KMP-MATCHER(S,P)
	next = COMPUTE-PREFIX-FUNCTION
	k = 0
	for i=1 to S.length
		while k > 0 and S[i] != P[k+1]	//失配的时候
			k = next[k]
		if S[i] == P[k+1]				//匹配成功
			k = k+1
		if k == P.length				//已经完全匹配
			print "Pattern occurs with shift" i-k
			k = next[k]
```





## C++实现

```C++
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int MAXN = 1e6+5;
int _next[MAXN];
string s,p;
inline void pre_next(){
    _next[0] = -1;
    int k = -1,len = p.length();
    for(int i = 1; i < len; ++i){
        while(k > -1 && p[k+1] != p[i])
            k = _next[k];
        if(p[k+1] == p[i])
            ++k;
        _next[i] = k;
    }
}
inline void KMP(){
    int p_len = p.length(),s_len = s.length();
    register int j = -1;
    for(register int i = 0; i < s_len; i++){
        while(j > -1 && p[j+1] != s[i])
            j = _next[j];
        if(p[j+1] == s[i])
            ++j;
        if(j == p_len-1){
            cout << i-j+1 << endl;
            j = _next[j];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> s >> p;
    pre_next();
    KMP();
    int p_len = p.length();
    for(int i = 0; i < p_len; i++)
        cout << _next[i]+1 << " ";
}
```

