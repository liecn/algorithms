class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        int res=9;
        // n=Math.min(n,10);
        for(int i=9;i>10-n;i--)
            res*= i;
        return (res+countNumbersWithUniqueDigits(n-1));
    }
}
