class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        int max_profit=INT_MIN;
        int min_price=prices[0];
        for(int i=1;i<n;i++){
            min_price=min(prices[i],min_price);
            max_profit=max(prices[i]-min_price,max_profit);
        }
        return max_profit;
    }
};
