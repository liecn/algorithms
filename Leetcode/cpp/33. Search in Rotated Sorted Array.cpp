class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1;
        int inflection_index=findMin(nums);
        int result;
        if(target<nums[inflection_index]) return -1;
        if(target>=nums[0]&&inflection_index) result=searchInsert(nums,target,0,inflection_index);
        else result=searchInsert(nums,target,inflection_index,nums.size());
        if(nums[result]!=target)result=-1;
        return result;
        
    }
private:
    int findMin(vector<int>& nums) {
        int hi=nums.size()-1;
        int lo=0;
        while(nums[lo]>nums[hi]){
            int mi=(lo+hi)>>1;
            (nums[lo]<=nums[mi])?lo=mi+1:hi=mi;
        }
        return lo;
    };
    int searchInsert(vector<int>& nums, int target,int start, int end) {
        int lo=start;
        int hi=end;
        if(lo==hi)return lo;
        while(lo<hi){
            int mi=(lo+hi)>>1;
            (target<nums[mi])?hi=mi:lo=mi+1;
        }
        return --lo;
    }
};
