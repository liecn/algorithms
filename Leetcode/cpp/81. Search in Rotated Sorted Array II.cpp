class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(!nums.size()) return 0;
        int inflection_index=findMin(nums);
        int result;
        if(target<nums[inflection_index]) return 0;
        if(target>=nums[0]&&inflection_index) result=searchInsert(nums,target,0,inflection_index);
        else result=searchInsert(nums,target,inflection_index,nums.size());
        if(nums[result]!=target) return 0;
        return 1;
    }
private:
    //return the minimum index of the minimum element
    int findMin(vector<int>& nums) {
        int hi=nums.size()-1;
        int lo=0;
        while(lo<hi&&nums[lo]==nums[hi])lo++;//avoid nums[lo]==nums[hi];
        while(nums[lo]>nums[hi]){
            int mi=(lo+hi)>>1;
            (nums[lo]<=nums[mi])?lo=mi+1:hi=mi;
            //cout<<lo<<","<<mi<<","<<hi<<endl;
        }
        return lo;
    };

    //return the index of the element which no more than target
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
