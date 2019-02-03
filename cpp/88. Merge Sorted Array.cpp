class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m_rank=0;
        int n_first=0;
        int n_end=0;
        nums1.resize(m);
        while(m_rank<nums1.size()&&n_end<n){
            if(nums1[m_rank]<=nums2[n_first])m_rank++;
            else{
                n_end=searchInsert(nums2,nums1[m_rank],n_first,n);
                nums1.insert(nums1.begin()+m_rank,nums2.begin()+n_first,nums2.begin()+n_end);
                n_first=n_end;
            }
        }
        if(m_rank==nums1.size())nums1.insert(nums1.end(),nums2.begin()+n_first,nums2.end());
    }
private:
    int searchInsert(vector<int>& nums, int target, int start, int end) {
        int lo=start;
        int hi=end;
        while(lo<hi){
            int mi=(lo+hi)>>1;
            (target<nums[mi])?hi=mi:lo=mi+1;
        }
        if(lo&&nums[--lo]!=target)lo++;
        return lo;
    }
};
