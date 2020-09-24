class Solution {
public:
    int uniquePaths(int m, int n) {
        long int top=1;
        long int bottom=1;
        int mi=min(m,n)-1;
        int ma=m+n-2;
        while(mi>0){   
            // cout<<ma<<","<<mi<<endl;
            top*=ma--;
            bottom*=mi--;
        }
        return top/bottom;
    }
};
