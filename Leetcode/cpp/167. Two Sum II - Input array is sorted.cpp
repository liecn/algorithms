class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2);
        result[1]=searchInsert(numbers,target-1)+1;
        if(result[0]==result[1])result[1]++;
        while(numbers[result[0]]+numbers[result[1]]!=target){
            if(numbers[result[0]]+numbers[result[1]]>target)result[1]--;
            else result[0]++;
        }
        result[0]++;
        result[1]++;
        return result;
    }
private:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size();
        while(lo<hi){
            int mi=(lo+hi)>>1;
            (target<nums[mi])?hi=mi:lo=mi+1;
        }
        return --lo;
    }
};

static int fast = []() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
