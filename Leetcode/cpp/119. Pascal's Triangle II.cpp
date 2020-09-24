class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1);
        int value;
        int mi;
        for(int i=1;i<rowIndex+1;i++){
            value=1;
            for(int j=1;j<i;j++){
                mi=result[j];
                result[j]+=value; 
                value=mi;     
            }   
        }
        return result;
    }
};
