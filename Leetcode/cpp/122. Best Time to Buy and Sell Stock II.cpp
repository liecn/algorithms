class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        int max_profit=0;
        int min_price=prices[0];
        for(int i=1;i<n-1;i++){//the last point is special
            min_price=min(prices[i],min_price);          
            if(prices[i+1]<prices[i]){
                max_profit+=prices[i]-min_price;
                min_price=prices[i+1];
            }
        }
        max_profit+=max(prices[n-1]-min_price,0);
        return max_profit;
    }
};
