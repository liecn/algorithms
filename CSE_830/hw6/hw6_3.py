# Complete the targetRotation function below.
import numpy as np
 
if __name__ == '__main__':
    mnr = input().rstrip().split()

    n_node = int(mnr[0]) # Number of rows

    n_edge = int(mnr[1]) # Number of columns

    n_matrix = np.zeros((n_node, n_node))

    for _ in range(n_edge):
        mnr = input().rstrip().split()
        a = int(mnr[0]) # Number of rows
        b = int(mnr[1]) # Number of columns
        n_matrix[a][b]=1
        n_matrix[b][a]=1
    mid=n_matrix 
    res=n_matrix
    for _ in range(n_node-1):
        mid=np.matmul(mid,n_matrix)
        res=res+mid
        res=(res!=0)
    n_path_potential=n_node-np.count_nonzero(res[0,:])
    n_path_node=np.squeeze((res[0,:]==0))
    ans=1
    while(n_path_potential!=0):
        first_ele=np.nonzero(n_path_node)[0][0]
        cur_path=res[first_ele,:]*n_path_node
        n_path_potential=n_path_potential-np.sum(cur_path)
        n_path_node=n_path_node^cur_path
        ans=ans+1

    print(ans)
