class Solution {
    public int maxSubArray(int[] nums) {
        int midRes=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.length;i++){
            midRes=Math.max(midRes+nums[i],nums[i]);
            res=Math.max(res,midRes);
        }
        return res;
    }
}
