class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return nums.size();
        int rank=0;
        for(int i=1;i<n;i++){
            if(nums.at(rank)!=nums.at(i))nums.at(++rank)=nums.at(i);
        }
        return rank+1;
    }
};
