class Solution {
    public int numDecodings(String s) {
        int n=s.length();
        if(n==0)return 0;
        long[] dp=new long[n+1];
        dp[0]=1;
        dp[1] = (s.charAt(0) == '0') ? 0 : 1*((s.charAt(0) == '*') ?9:1);
        for(int i=1;i<n;i++){
            int index=i+1;
            dp[index]=0;
            if(s.charAt(i)!='0'){
                dp[index]+=(dp[i]*((s.charAt(i) == '*') ?9:1));
            }
            if(s.charAt(i) != '*'&&s.charAt(i-1) != '*'){
                int twoDigits = Integer.parseInt(s.substring(i - 1, i+1));
                if (twoDigits >= 10 && twoDigits <= 26) {
                    dp[index] += dp[i - 1];
                }
            }
            else if(s.charAt(i) != '*'&&s.charAt(i-1) == '*'){
                int midS=Integer.parseInt(s.substring(i,i+1));
                if(midS<7&&midS>=0)dp[index] += (dp[i - 1]*2);
                else dp[index] += dp[i - 1]; 
            }
            else if(s.charAt(i) == '*'&&s.charAt(i-1) != '*'){
                if(s.charAt(i-1)=='1')dp[index] += (dp[i - 1]*9);
                if(s.charAt(i-1)=='2')dp[index] += (dp[i - 1]*6);
            }
            else dp[index] += (dp[i - 1]*15);
            dp[index] %= 1000000007;
        }
        return (int)dp[n];
    }
}
