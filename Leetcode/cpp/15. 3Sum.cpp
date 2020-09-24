class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n=nums.size();
        if(n<3) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                if(nums[start]+nums[end]+nums[i]>0)end--;
                else if(nums[start]+nums[end]+nums[i]<0)start++;
                else {
                    result.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    while(nums[start]==nums[start-1])start++;
                    while(nums[end]==nums[end+1])end--;
                }     
            }
            while(nums[i+1]==nums[i])i++;
        }
        return result;
    }
};
