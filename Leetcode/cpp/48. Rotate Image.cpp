class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(!matrix.size())return;
        int n=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-1-j]); 
            }
        }
        int rank=n;
        for(int i=0;i<n;i++){
            rank--;
            for(int j=0;j<rank;j++){
                swap(matrix[i][j],matrix[n-1-j][rank]); 
            }
        }
    }
};
