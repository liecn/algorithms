class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        if(!n) return 0;
        int result=INT_MAX;
        int start=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=s){
                result=min(result,i-start+1);
                sum-=nums[start++];
            }
        }
        if(result==INT_MAX)return 0;
        return result;
    }
};
