class Solution {
public:
    int findMin(vector<int>& nums) {
        int hi=nums.size()-1;
        int lo=0;
        while(lo<hi&&nums[lo]==nums[hi])lo++;//avoid nums[lo]==nums[hi];
        while(nums[lo]>nums[hi]){
            int mi=(lo+hi)>>1;
            (nums[lo]<=nums[mi])?lo=mi+1:hi=mi;
            //cout<<lo<<","<<mi<<","<<hi<<endl;
        }
        return nums[lo];
    }
};
