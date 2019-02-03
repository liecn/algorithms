class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int r=x;
        while(l!=r){
            double mid=(l+r)/2;
            if (mid *mid < x) l = mid +1;
            else r = mid;
        }
        return l * l == x ? l : l -1;
    }
};
