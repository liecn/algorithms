class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int curSum1 = 1;
        int curSum2 = 1;
        for (int num : nums) {
            int mid=curSum2;
            curSum2= min(min(curSum2 * num,curSum1 * num),num);
            curSum1 = max(max(mid * num,curSum1 * num),num);
            if(curSum2>curSum1)swap(curSum2,curSum1);
            res = max(res, curSum1);
        }
        return res;
    }
};
