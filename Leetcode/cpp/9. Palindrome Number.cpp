class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        int std=x;
        int result=0;
        while(x){
            result=result*10+x%10;
            x=x/10;
        }
        return std==result;
    }
};
