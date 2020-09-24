class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int replace;
        int rank=n-1;
        while(rank&&nums.at(rank)<=nums.at(rank-1))rank--;
        if(rank){
            int rank_index=rank;
            while(rank_index<n&&nums.at(rank-1)<nums.at(rank_index))rank_index++;
            replace=nums.at(rank-1);
            nums.at(rank-1)=nums.at(rank_index-1);
            nums.at(rank_index-1)=replace; 
        }
        sort(nums.begin()+rank,nums.end());
    }
};
