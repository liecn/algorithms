class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int result=nums[0]+nums[1]+nums[n-1];
        for(int i=0;i<n;i++){
            int start=i+1;
            int end=n-1;
            if(nums[start]+nums[end]+nums[i]==target) return target;
            while(start<end){
                if (nums[start]+nums[end]+nums[i]==target)return target;
                else if(nums[start]+nums[end]+nums[i]> target){
                    if(nums[start]+nums[end]+nums[i]-target<abs(result-target))result=nums[start]+nums[end]+nums[i];
                    end--;
                }
                else{
                    if(target-(nums[start]+nums[end]+nums[i])<abs(result-target))result=nums[start]+nums[end]+nums[i];
                    start++;
                }
            }
            while(nums[i+1]==nums[i])i++;
        }
        return result;
    }
};
