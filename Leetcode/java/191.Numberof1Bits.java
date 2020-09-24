public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int res=0;
        //test the highest digit due to the lack of unsigned integer type in Java
        if((n&1<<31) != 0){
            n=n&(~(1<<31));
            res=1;
        }
        while(n>0){
	    // res+=n&1;
            // n=n>>1;
             res++;
             n&=(n-1);
        }
        return res;
    }
}
