/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//ST表 + 二分搜索
//二分还挺难写的 -_-|
struct ST{
    int f[10001][32];
    inline int highbit(int x){return 31-__builtin_clz(x);}
    void init(int *v,int n){
        for(int i = 0; i < n; i++) f[i][0] = v[i];
        int len = highbit(n);
        for(int j = 1; j <= len; j++){
            int t = n-(1<<j)+1;
            for(int i = 0; i < t; i++)
                f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    int getmax(int l,int r){
        assert(l <= r); 
        int p = highbit(r-l+1);
        return max(f[l][p],f[r-(1<<p)+1][p]);
    }
};
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int arr[10001],len = 0;
        vector<int> ans;
        ListNode* cur = head;
        while(cur){
            arr[len++] = cur->val;
            cur = cur->next;
        }
        ST rec;
        rec.init(arr,len);
        for(int i = 0; i < len-1; i++){
            int l = i+1,r = len-1;
            if(rec.getmax(l,r) <= arr[i]) {ans.push_back(0); continue;}
            while(l < r){
                int mid = l+(r-l)/2;
                int tmp = rec.getmax(i+1,mid);
                if(tmp <= arr[i]) l = mid+1;
                else r = mid;
            }
            ans.push_back(arr[l]);
        }
        ans.push_back(0);
        return ans;
    }
};