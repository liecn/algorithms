class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n));
        int dim0=0;
        int dim1=0;
        int flag=0;
        int flag_bottom=0;
        int flag_top=n-1;
        int value=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                result[dim0].at(dim1)=value++;
                if(flag==0){
                    if(dim1<flag_top)dim1++;
                    else {
                        flag=1;
                        dim0++;
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
                    if(dim1>flag_bottom)dim1--;
                    else {
                        flag=3;
                        dim0--;
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
