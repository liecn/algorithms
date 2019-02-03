class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        int num=2;//the number of transactions
        int local[num+1]{0};
        int global[num+1]{0};
        int diff=0;
        for(int i=1;i<n;i++){
            diff=prices[i]-prices[i-1];
            for(int j=num;j;j--){
                local[j]=max(global[j-1],local[j])+diff;
                global[j]=max(local[j],global[j]);
            }
        }     
        return global[num];
    }
    
};
