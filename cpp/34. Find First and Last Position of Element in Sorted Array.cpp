class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        int n=nums.size();
        if(!n) return result;
        int hi=n;
        int lo=0;
        while(lo<hi){
            int mi=(lo+hi)>>1;
            (target<nums.at(mi))?hi=mi:lo=mi+1;
        }
        if(lo&&nums.at(--lo)==target){
            result[1]=lo;
            hi=lo;
            lo=0;
            while(lo<hi){
                int mi=(lo+hi)>>1;
                (target-1<nums.at(mi))?hi=mi:lo=mi+1;
            }
            result[0]=lo;
        }
        return result;
    }
};
