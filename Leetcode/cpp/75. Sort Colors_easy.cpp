class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int cur=0;
        while(cur<=end){
            if(nums[cur]==0){
                swap(nums[cur],nums[start]);
                start++;
                cur++;
            }
            else if(nums[cur]==2){
                swap(nums[cur],nums[end]);
                end--;
            }
            else cur++;
        }
        return;
    }
};
