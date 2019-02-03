class Solution {
public:
    int reverse(int x) {
        // long int biggest32 = (1<<31) - 1;
        long int result=0;
        // cout<<biggest32<<endl;
        while(x){
            result=((result*10+x%10)>INT_MAX||(result*10+x%10)<INT_MIN)?0:(result*10+x%10);
            x=x/10;
            // cout<<result<<","<<(result*10)<<endl;
        }
        return result;
    }
};
