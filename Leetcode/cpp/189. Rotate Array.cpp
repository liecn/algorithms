class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2) return;
        k%=n;
        nums.insert(nums.begin(),nums.end()-k,nums.end());
        nums.resize(n);
    }
};
