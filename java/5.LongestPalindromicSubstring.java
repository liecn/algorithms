class Solution {
    public String longestPalindrome(String s) {
        if(s==null||s.length()<1)return "";
        int st=0;
        int en=0;
        for(int i=0;i<s.length();i++){
            int len1=expandAroundCenter(s,i,i);
            int len2=expandAroundCenter(s,i,i+1);
            int len=Math.max(len1,len2);
            if(len>en-st){
                st=i-(len-1)/2;
                en=i+len/2;
            }
        }
        return s.substring(st,en+1);
    }
    private int expandAroundCenter(String s, int left, int right) {
        while(left>=0&&right<s.length()&&s.charAt(left)==s.charAt(right)){
            left--;
            right++;
      }
    return right-left+1-2;
    }
}
