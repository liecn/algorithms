class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length;
        int cols = rows > 0 ? matrix[0].length : 0;
        int[][] res = new int[rows + 1][cols + 1];
        int maxres = 0;
        for(int i=0;i<rows;i++){
            res[i][0]=(int)(matrix[i][0]-'0');
       maxres=Math.max(res[i][0],maxres);
        }
         for(int i=1;i<cols;i++){
            res[0][i]=(int)(matrix[0][i]-'0');
       maxres=Math.max(res[0][i],maxres);
         }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                 if(matrix[i][j] == '1')res[i][j]=Math.min(Math.min(res[i-1][j-1],res[i-1][j]),res[i][j-1])+1;
                maxres=Math.max(res[i][j],maxres);
             }
        }
        return maxres*maxres;
    }
}
