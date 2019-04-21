class Solution {
    //a^0=a; a^a=0
    public int singleNumber(int[] nums) {
        int res=0;
        for(int j=0;j<nums.length;j++){
                res^=nums[j];
        }
        return res;

    }
}
