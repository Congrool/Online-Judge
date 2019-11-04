class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0) return nums2.size()&1?nums2[nums2.size()>>1]:(1.0*nums2[(nums2.size()-1)>>1]+nums2[((nums2.size()-1)>>1) + 1])/2;
        if(nums2.size() == 0) return nums1.size()&1?nums1[nums1.size()>>1]:(1.0*nums1[(nums1.size()-1)>>1]+nums1[((nums1.size()-1)>>1) + 1])/2;
        int r = nums1.size()-1;int l = 0; 
    int tot = nums1.size()+nums2.size();
    double ans = 0.0; int flag = 0;
    while(l <= r){
        int mid = l+((r-l)>>1);
        int tmp = nums1[mid];
        int p = lower_bound(nums2.begin(),nums2.end(),tmp)-nums2.begin();
        if(tot & 1){
            if(p + mid+1< (tot+1)>>1) l = mid+1;
            else if(p + mid+1 == (tot+1)>>1) {ans = 1.0*tmp; flag = 1; break;}
            else r = mid-1;
            continue;
        }
        if(p + mid+1 < tot>>1) l = mid+1;
        else if(p + mid+1 == tot>>1){
            if(mid+1 >= nums1.size()) ans = (1.0*nums2[p]+nums1[mid])/2;
            else if(p >= nums2.size()) ans = (1.0*nums1[mid]+nums1[mid+1])/2;
            else ans = (1.0*min(nums1[mid+1],nums2[p])+tmp)/2;
            flag = 1;
            break;
        } 
        else r = mid-1;
    }
    if(!flag){
        l = 0; r = nums2.size()-1;
        while(l <= r){
            int mid = l+((r-l)>>1);
            int tmp = nums2[mid];
            int p = lower_bound(nums1.begin(),nums1.end(),tmp)-nums1.begin();
            if(tot & 1){
                if(p + mid+1 < (tot+1)>>1) l = mid+1;
                else if(p + mid+1 == (tot+1)>>1) {ans = 1.0*tmp; flag = 1; break;}
                else r = mid-1;
                continue;
            }
            if(p + mid+1 < tot >> 1) l = mid+1;
            else if(p + mid+1 == tot>>1){
                if(mid+1 >= nums2.size()) ans = (1.0*nums1[p]+nums2[mid])/2;
                else if(p >= nums1.size()) ans = (1.0*nums2[mid]+nums2[mid+1])/2;
                else ans = (1.0*min(nums2[mid+1],nums1[p])+tmp)/2;
                flag = 1;
                break;
            } 
            else r = mid-1;
        }
    }
    if(!flag){
        int p = lower_bound(nums1.begin(),nums1.end(),nums2[r])-nums1.begin();
        int _p = lower_bound(nums1.begin(),nums1.end(),nums2[r]+1)-nums1.begin();
        if(p + r + 1 < (tot>>1) && _p + r + 1 > (tot)>>1) ans =1.0*nums2[r]; 
        else ans = (1.0*nums2[r]+nums2[l])/2;
    }
        return ans;
    }
};