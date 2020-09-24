class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(nums[start]==0)start++;
        while(nums[end]==2)end--;
        int i=start;
        int j=end;
        while(1){
            while(nums[i]==1)i++;
            if(j<i)break;
            if(nums[i]==2){
                swap(nums[end--],nums[i]);
                while(nums[start]==0)start++;
                while(nums[end]==2)end--;
                i=start;
                j=end;
            }
            if(nums[i]==0)swap(nums[start++],nums[i]);
            while(nums[j]==1)j--;
            if(j<i)break;
            if(nums[j]==0){
                swap(nums[j],nums[start++]);
                while(nums[start]==0)start++;
                while(nums[end]==2)end--;
                i=start;
                j=end;
            }    
            if(nums[j]==2)swap(nums[end--],nums[j]);
        }
    }
};
