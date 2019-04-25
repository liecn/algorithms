class Solution {
    public int[] singleNumber(int[] nums) {
        int res=0;
        int sum=0;
        for(int j=0;j<nums.length;j++){
                res^=nums[j];
        }
        int bit=0;
        while((res&(1<<bit))==0){
            bit++;
        }
        // int bit = res & ~(res-1);
        System.out.println(bit);
        int res1=0;
        int res2=0;
        for(int j=0;j<nums.length;j++){
            if((nums[j]&(1<<bit))!=0) res1^=nums[j];
            else res2^=nums[j];
        }
        int [] resF={res1,res2};
        return resF;
    }
}
