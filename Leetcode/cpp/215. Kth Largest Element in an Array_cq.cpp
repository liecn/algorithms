class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size()-k+1;
        priority_queue<int> mypq;
        for(int i=0;i<n;i++)mypq.push(nums[i]);
        for(int i=n;i<nums.size();i++){
            if(nums[i]<mypq.top()){
                mypq.pop();
                mypq.push(nums[i]);
            } 
        }
        return mypq.top();
        
        
    }
};
