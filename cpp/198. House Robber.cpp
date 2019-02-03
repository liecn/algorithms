class Solution {
public:
    int rob(vector<int>& nums) {
        int a=0;
        int b=0;
        for(int i=0;i<nums.size();i++){
            a=max(b,a+nums[i]);
            swap(a,b);
        }
        return b;
    }
};
