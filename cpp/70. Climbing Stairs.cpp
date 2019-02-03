class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        int a=1;
        int b=2;
        int t=n-2;
        while(t--){
            b=a+b;
            a=b-a;
        }
        return b;
    }
};
