class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0||s.size()==1)return s.size();
        int len=0;
        int i=0;
        int start_mid=0;
        int flag[127]={0};
        int len_mid=0;
        while(1){
            if(flag[s[i]]==0){
                flag[s[i]]=i+1;
                len_mid++;
                i++;
                if(i<s.size())continue;
            }
            if(len_mid>len)len=len_mid;
            if(i>=s.size())break;
            int tt=flag[s[i]];
            for(int j=start_mid;j<i;j++){
                flag[s[j]]=0;
            }
            start_mid=tt;
            i=tt;
            len_mid=0;           
        }
        return len;
    }
};
