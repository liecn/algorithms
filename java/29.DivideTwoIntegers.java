class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        long lDividend = Math.abs((long) dividend);      
        long lDivisor = Math.abs((long) divisor);        
        int sign = (dividend ^ divisor) >> 31;
        long ans = 0;
        while(lDividend >= lDivisor){
            long curr = 1;
            long tempDivisor = lDivisor;
            while(lDividend >= tempDivisor){
                if(lDividend < tempDivisor + tempDivisor) break; 
                curr *=2;
                tempDivisor *= 2;
            }
            lDividend -= tempDivisor;
            ans += curr;
        }
        if(sign == -1) ans*= -1;
        if(ans < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        else if(ans > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        return (int)ans;
    }
}
