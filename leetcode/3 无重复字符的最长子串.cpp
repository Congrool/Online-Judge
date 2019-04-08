/*
这个玩意花了不少时间，
暴力很容易，时间复杂度太高
这个是采用了节取法的优化
重点在于讨论
首先：从头开始遍历字符串，截取字串，遇到重复字符时不需要调整j,只要i+1就行
因为，如果缩j的话，所得字串sub(i,j)长度肯定不够。
以下是讨论：
如果没有遇到重复字符：j++，并将新字符加入哈希表
如果遇到重复字符1：新字符和子串第一个字符相同：i++
				2: 新字符不和字串第一个字符相同，即重复字符在子串中间：
					找到中间重复字符的位置pos, 从哈希表中删除从i到pos的字符
					i = pos
*/
int lengthOfLongestSubstring(string s) {
    int res = 0;
    unordered_set<char> ithas;
    string::size_type i = 0,j = 0;
    for(j = 0; j < s.size(); j++){
        if(ithas.count(s[j])){
            if(s[j]!=s[i]){
                ithas.insert(s[j]);
                ithas.erase(s[i]);
                string::size_type npos = s.find_last_of(s[j],j-1);
                for(;i<npos;i++)
                    ithas.erase(s[i]);
            }
            i++;
            continue;
        } 
        else{
            int sublen = j-i+1;
            ithas.insert(s[j]);
            res = max(res,sublen);           
        }
    }
    return res;
}
/*方法2：
left始终指向子串的前一位
rec[s[i]]始终记录下一个重复位置
如s = abcabcd
到s[3]出现重复，rec[s[3]] = 0 则 left 滑动到0
强的呀。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> rec(256,-1);
        int i;
        int left = -1;
        int res = 0;
        for(i = 0; i < s.length(); i++){
            left = max(rec[s[i]],left);
            rec[s[i]] = i;
            res = max(res,i-left);
        }
        return res;
    }
};