class Solution {
    public int hammingDistance(int x, int y) {
	//record the true/false state for each state;
	int midR=x^y;
        int res=0;
        while(midR>0){
	    //count the number of 1 in midR	
            // res+=midR&1;
            // midR=midR>>1;
            res++;
            midR&=(midR-1);
	}
        return res;
    }
}
