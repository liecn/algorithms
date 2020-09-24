class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n=matrix.size();
        if(!n) return result;
        int m=matrix[0].size();
         if(!m) return result;
        result.resize(m*n);
        int dim0=0;
        int dim1=0;
        int flag=0;
        int flag_bottom=0;
        int flag_top=n-1;
        int column_flag_bottom=0;
        int column_flag_top=m-1;
        int value=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[value++]=matrix[dim0].at(dim1);
                if(flag==0){
                    if(dim1<column_flag_top)dim1++;
                    else {
                        flag=1;
                        dim0++;
                        column_flag_top--;
                    }
                }
                else if(flag==1){
                    if(dim0<flag_top)dim0++;
                    else {
                        flag=2;
                        dim1--;
                        flag_top--;
                    }
                }
                else if(flag==2){
                    if(dim1>column_flag_bottom)dim1--;
                    else {
                        flag=3;
                        dim0--;
                        column_flag_bottom++;
                    }
                }
                else{
                    if(dim0>flag_bottom+1)dim0--;
                    else {
                        dim1++;
                        flag=0;
                        flag_bottom++;
                    }
                }
            }
        }
        return result;
    }
};
