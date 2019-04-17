class Solution {
    int total = Integer.MAX_VALUE;
    public int coinChange(int[] coins, int amount) {
        if(amount==0)return 0;
        Arrays.sort(coins);
        count(amount,coins.length-1,coins,0);
        return total==Integer.MAX_VALUE?-1:total;
        
    }
	void count(int amount, int index, int[] coins, int count){
		if(index<0||count>=total-1)return;
        int quotient=amount/coins[index];
        for(int i=quotient;i>-1;i--){
            int newCount=count+i;
            int remainder=amount-coins[index]*i;
            if (newCount>=total) break;
            if(remainder>0&&newCount<total)count(remainder, index-1, coins, newCount);
            else total=newCount;
            }
	}
}
