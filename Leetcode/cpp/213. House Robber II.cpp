class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        if(n<0)return 0;
        if(n==0)return nums[0];
        int a=0;
        int b=0;
        int flag=0;
        for(int i=0;i<n;i++){
            a=max(a+nums[i],b);
            swap(a,b);
        }
        if(a+nums[n]<=b)return b;
        else{
            flag=b;
            a=0;
            b=0;
            for(int i=0;i<n;i++){
                a=max(a+nums[i+1],b);
                swap(a,b);
            } 
        }
        return max(flag,b);
    }
};
