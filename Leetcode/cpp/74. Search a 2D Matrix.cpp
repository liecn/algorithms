class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(!n||!matrix[0].size())return 0;
        vector<int> rows;
        for(int i=0;i<n;i++)rows.push_back(matrix[i].at(0));
        int row_rank=searchInsert(rows,target);
        if(row_rank<0)return 0;
        int column_rank=searchInsert(matrix[row_rank],target);
        if(matrix[row_rank].at(column_rank)==target)return 1;
        return 0;
    }
private:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size();
        while(lo<hi){
            int mi=(lo+hi)>>1;
            (target<nums[mi])?hi=mi:lo=mi+1;
        }
        return --lo;
    }
};
