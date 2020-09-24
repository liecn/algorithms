class Solution {
    public int getSum(int a, int b){
	//digit manipulation, ^ save the odd digits,and & save the even digits with value 1 which can contribut to the final sum. Moreover, <<1 means when 1&1, the sum result is (1&1)<<1.  
        return b==0?a:getSum(a^b,(a&b)<<1);
    }
}
