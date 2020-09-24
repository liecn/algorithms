class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row_length=matrix.length;
        if(row_length==0)return false;
        int column_length=matrix[0].length;
        if(column_length==0)return false;
        int row=0;
        int column=column_length-1;
        while(row<row_length&&column>=0){
            int index_row=Math.min(row_length-1,row);
            int index_column=Math.max(0,column);
            if(target>matrix[index_row][index_column])row++;
            else if(target<matrix[index_row][index_column])column--;
            else return true;
        }
        return false;
    }
}
