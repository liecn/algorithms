class Solution {
public:
    int findMin(vector<int>& nums) {
        int hi=nums.size()-1;
        int lo=0;
        while(nums[lo]>nums[hi]){
            int mi=(lo+hi)>>1;
            (nums[lo]<=nums[mi])?lo=mi+1:hi=mi;
        }
        return nums[lo];
    }
};
