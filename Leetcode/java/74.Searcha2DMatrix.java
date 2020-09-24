class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row_length=matrix.length;
        if(row_length==0)return false;
        int column_length=matrix[0].length;
        if(column_length==0)return false;
        int row=0;
        int column=column_length-1;
        while(row<row_length&&target>matrix[row][column]){
            row++;
        }
        if(row==row_length) return false;
        while(0<=column&&target<matrix[row][column]){
            column--;
        }
        if(column<0) return false;
        if(target==matrix[row][column])return true;
        return false;        
    }
}
