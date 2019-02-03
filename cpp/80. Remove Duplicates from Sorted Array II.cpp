class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(count>1){
                    nums.erase (nums.begin()+i-count+1,nums.begin()+i);
                    i-=(count-1);
                }
                count=0;
            }
            else count++;
        }
        if(count>1)nums.erase (nums.end()-count+1,nums.end());
        return nums.size();
    }
};
