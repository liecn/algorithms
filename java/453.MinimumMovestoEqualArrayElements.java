class Solution {
    public int minMoves(int[] nums) {
        if (nums.length == 0) return 0;
        int min = nums[0];
        int res = 0;
        for (int n : nums) {
            min = Math.min(min, n);
            res += n;
        }
        return res-nums.length*min;
    }
}
