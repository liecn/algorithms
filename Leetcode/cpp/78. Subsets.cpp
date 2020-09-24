class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //sort(nums.begin(),nums.end());     
        int n = nums.size();
        int subsetNum = pow(2,n);        
        vector<vector<int>> result(subsetNum,vector<int>());
        // for(int i=0; i<n; i++){
        for(int j=0; j<subsetNum; j++){
            for(int i=0; i<n; i++){
                if(j >> i & 1){
                    result[j].push_back(nums[i]);
                }
            }
        }
        return result;
    }
};
