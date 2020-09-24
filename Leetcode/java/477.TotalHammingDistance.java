class Solution {
    public int totalHammingDistance(int[] nums) {
        int res=0;
        int n=nums.length;
        for(int i=0;i<32;i++){
            int count=0;
	    //Do not compute for each number but for each bit. In other words, think this question in column(digit) not row(number)
            for(int j=0;j<n;j++){
                count+=(nums[j]>>i&1);
            }
            res+=count*(n-count);
        }
        return res;
    }
}
