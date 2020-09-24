# Complete the targetRotation function below.
def targetRotation(matrix, r):
    m= len(matrix)
    n=len(matrix[0])
    r_circle=int(min(m,n)/2)
    
    for idx_circle in range(r_circle):
        row_end=m-idx_circle
        col_end=n-idx_circle
        
        circle_list=[]

        idx_insert_row=idx_circle
        idx_insert_col=idx_circle
        while(idx_insert_row<row_end):
            circle_list.append(matrix[idx_insert_row][idx_insert_col])
            idx_insert_row=idx_insert_row+1
        idx_insert_row=idx_insert_row-1
        while(idx_insert_col<col_end-1):
            idx_insert_col=idx_insert_col+1
            circle_list.append(matrix[idx_insert_row][idx_insert_col])
        while(idx_insert_row>idx_circle):
            idx_insert_row=idx_insert_row-1
            circle_list.append(matrix[idx_insert_row][idx_insert_col])
        while(idx_insert_col>idx_circle):
            idx_insert_col=idx_insert_col-1
            circle_list.append(matrix[idx_insert_row][idx_insert_col])
        
        circle_list=circle_list[:-1]
        shift_loc=(len(circle_list)-r%len(circle_list))
        circle_list=circle_list[shift_loc:]+circle_list[:shift_loc]
        
        circle_list_idx=0
        while(idx_insert_row<row_end):
            matrix[idx_insert_row][idx_insert_col]=circle_list[circle_list_idx]
            idx_insert_row=idx_insert_row+1
            circle_list_idx=circle_list_idx+1
        idx_insert_row=idx_insert_row-1
        while(idx_insert_col<col_end-1):
            idx_insert_col=idx_insert_col+1
            matrix[idx_insert_row][idx_insert_col]=circle_list[circle_list_idx]
            circle_list_idx=circle_list_idx+1
        while(idx_insert_row>idx_circle):
            idx_insert_row=idx_insert_row-1
            matrix[idx_insert_row][idx_insert_col]=circle_list[circle_list_idx]
            circle_list_idx=circle_list_idx+1
        while(idx_insert_col>idx_circle+1):
            idx_insert_col=idx_insert_col-1
            matrix[idx_insert_row][idx_insert_col]=circle_list[circle_list_idx]
            circle_list_idx=circle_list_idx+1


if __name__ == '__main__':
    mnr = input().rstrip().split()

    m = int(mnr[0]) # Number of rows

    n = int(mnr[1]) # Number of columns

    r = int(mnr[2]) # Number of rotations

    matrix = []

    for _ in range(m):
        matrix.append(list(map(int, input().rstrip().split())))

    targetRotation(matrix, r)
    print('\n'.join([' '.join([str(item) for item in row]) 
      for row in matrix]))
