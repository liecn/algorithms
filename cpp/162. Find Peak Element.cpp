class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        int mi;
        while(lo<hi){
            mi=(lo+hi)>>1;
            if(nums[mi]>nums[mi+1])hi=mi;
            else lo=mi+1;
        }
        return lo;
            
    }
};
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
