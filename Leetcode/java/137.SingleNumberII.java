class Solution {
    public int singleNumber(int[] nums) {
    int ans = 0;
    for(int i = 0; i < 32; i++) {
        int sum = 0;
        for(int j = 0; j < nums.length; j++) {
            int bit=1<<i;
            if((nums[j] & bit) != 0) {
                sum++;
                sum %= 3;
            }
        }
        if(sum != 0) {
            ans += sum << i;
        }
    }
    return ans;
}
}
//learned method:
// class Solution {
//     public int singleNumber(int[] nums) {
//             int x1 = 0, x2 = 0, mask = 0; 
//             for (int i : nums) {
//                 x2 ^= x1 & i;
//                 x1 ^= i;
//                 mask = ~(x1 & x2);
//                 x2 &= mask;
//                 x1 &= mask;
//             }
//             return x1;  
//         }
// }
