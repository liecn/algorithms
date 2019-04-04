class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<1)return "";
        int st=0;
        int en=0;
        int len=0;
        for(int i=0;i<s.length();i++){
            int len1=expandAroundCenter(s,i,i);
            int len2=expandAroundCenter(s,i,i+1);
            len=max(len1,len2);
            if(len>en-st){
                st=i-(len-1)/2;
                en=i+len/2;
            }
        }
        return s.substr(st,en-st+1);
    }
    int expandAroundCenter(string s, int left, int right) {
         while(left>=0&&right<s.length()&&s.at(left)==s.at(right)){
            left--;
            right++;
        }
    return right-left+1-2;
    }
};
