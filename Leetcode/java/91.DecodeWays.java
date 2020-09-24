class Solution {
    public int numDecodings(String s) {
        int n=s.length();
        if(n==0)return 0;
        int[] dp=new int[n+1];
        dp[0]=1;
        dp[1] = (s.charAt(0) == '0') ? 0 : 1;
        for(int i=1;i<n;i++){
            int index=i+1;
            dp[index]=0;
            if(s.charAt(i)!='0'){
                dp[index]+=(dp[i]*1);
            }
            int twoDigits = Integer.parseInt(s.substring(i - 1, i+1));
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[index] += dp[i - 1];
            }
        }
        return dp[n];
    }
}
