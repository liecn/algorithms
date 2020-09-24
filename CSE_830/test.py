import math
# Complete the targetRotation function below.
def targetRotation(matrix, r):
    m= len(matrix)
    n=len(matrix[0])
    r_circle=math.min(m,n)/2
    for idx in range(r):
        for idx_circle in range(r_circle):
            row_end=m-idx_circle
            col_end=n-idx_circle

if __name__ == '__main__':
    mnr = input().rstrip().split()

    m = int(mnr[0]) # Number of rows

    n = int(mnr[1]) # Number of columns

    r = int(mnr[2]) # Number of rotations

    matrix = []

    for _ in range(m):
        matrix.append(list(map(int, input().rstrip().split())))

    targetRotation(matrix, r)
    print(matrix[1][1])