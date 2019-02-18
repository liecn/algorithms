class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size();
        int l2=nums2.size();
        if(l1>l2){
            l1=nums2.size();
            l2=nums1.size();
            nums1.swap(nums2);
        }    
        if(l2==0) throw "Invalid array!";
        int imin=0,imax=l1,ihalf=(l1+l2+1)/2;
        int max_of_left,min_of_right;
        while(imin<=imax){
            int i=(imin + imax) / 2;
            int j=ihalf-i;
            if(i<l1&&nums2[j-1]>nums1[i])
                imin=i+1;
            else if(i>0&&nums1[i-1]>nums2[j])
                imax=i-1;
            else{
                if(i==0)max_of_left=nums2[j-1];
                else if(j==0)max_of_left=nums1[i-1];
                else max_of_left=max(nums1[i-1],nums2[j-1]);
                
                if((l1+l2)%2==1)return double(max_of_left);
                
                if(i==l1)min_of_right=nums2[j];
                else if(j==l2)min_of_right=nums1[i];
                else min_of_right=min(nums1[i],nums2[j]);
                return (max_of_left + min_of_right) / 2.0;
            }
        }
        throw "invaild array";
    }
};
