class Solution {
    typedef long long ll;
public:
    int divide(int dividend, int divisor) {
        ll sign = 1;
        if(dividend < 0) sign = -1;
        if(divisor < 0 ) sign = (sign == -1?1:-1);
        ll x = dividend<0?-(ll)dividend:dividend;
        ll y = divisor<0?-(ll)divisor:divisor;
        ll base = y,t = 1,ans = 0;
        while(x >= y){
            while(true){
                if(base + base>= x) break;
                base += base;
                t += t;
            }
            ans += t;
            x -= base;
            base = y;
            t = 1;
        }      
        if(sign == 1) return ans>INT_MAX?INT_MAX:ans;
        return -ans;
    }
};