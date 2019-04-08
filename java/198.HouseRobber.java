class Solution {
    public int rob(int[] nums) {
        if(nums.length==0)  return 0;
        if(nums.length==1) return nums[0];
        if(nums.length==2) return Math.max(nums[0],nums[1]);
        int res1=nums[0];
        int res2=nums[1];
        int res=Math.max(nums[0],nums[1]);
        for(int i=2;i<nums.length;i++){
                int mid=res2;
                res2=Math.max(res1+nums[i],res2);   
                res1=Math.max(res1,mid);
                res=Math.max(res,Math.max(res1,res2)); 
        }
        return res;
    }
}
