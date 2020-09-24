class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        if(n==1) return strs[0];
        int result=1;
        int i=1;
        int min_index=20000;
        for(int j=0;j<n;j++)min_index=min_index<strs[j].length()?min_index:strs[j].length();
        while(1){
            while(i<n&&!strs[i].substr(0,result).compare(strs[0].substr(0,result)))i++;
            if(i<n||result>min_index)break;  
            result++;
            i=1;
        }
        return strs[0].substr(0,result-1);
    }
};
