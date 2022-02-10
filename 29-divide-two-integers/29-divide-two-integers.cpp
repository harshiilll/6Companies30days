class Solution {
public:
   int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (dividend == INT_MIN and divisor == -1) return INT_MAX;
        if (divisor == -1) return -dividend;
        if (divisor == INT_MIN) return (dividend == divisor)?1:0;
        
        int sign = 1;
        if (dividend > 0 and divisor < 0) sign = -1;
        if (dividend < 0 and divisor > 0) sign = -1;
       
        int ans = 0;
        if (dividend == INT_MIN){
            ans += 1;
            if (divisor < 0) dividend -= divisor;
            if (divisor > 0) dividend += divisor;
        }
        
        dividend = abs(dividend);
        divisor = abs(divisor);
    
        while (dividend >= divisor){
            int tmp = divisor;
            int num = 1;
            while (dividend - tmp >= tmp){
                tmp <<= 1;
                num <<= 1;
            }
            dividend -= tmp;
            ans += num;
        }      
    
        return (sign == 1)?ans:-ans;
        
    }
};