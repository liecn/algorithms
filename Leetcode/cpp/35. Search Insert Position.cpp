class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size();
        while(lo<hi){
            int mi=(lo+hi)>>1;
            (target<nums[mi])?hi=mi:lo=mi+1;
        }
        if(lo&&nums[--lo]!=target)lo++;
        return lo;
    }
};
