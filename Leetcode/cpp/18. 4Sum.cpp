class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n=nums.size();
        if(n<4) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int start=j+1;
                int end=n-1;
                while(start<end){
                    if(nums[start]+nums[end]+nums[i]+nums[j]>target)end--;
                    else if(nums[start]+nums[end]+nums[i]+nums[j]<target)start++;
                    else {
                        result.push_back({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                        while(nums[start]==nums[start-1])start++;
                        while(nums[end]==nums[end+1])end--;
                    }     
                }
                while(nums[j+1]==nums[j])j++;
            }
            while(nums[i+1]==nums[i])i++;
        }
        return result;
    }
};
