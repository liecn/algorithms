class Solution {
    public int maxProduct(int[] nums) {
        int midRes=nums[0];
        int midNegRes=nums[0];
        int res=nums[0];
        int midMin;
        int midMax;
        for(int i=1;i<nums.length;i++){ 
            midMin = Math.min(midNegRes*nums[i],midRes*nums[i]);
            midMax = Math.max(midNegRes*nums[i],midRes*nums[i]);
            midNegRes=Math.min(midMin,nums[i]);
            midRes=Math.max(midMax,nums[i]);
            res=Math.max(res,midRes);
        }
        return res;
    }
}
