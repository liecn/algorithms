class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        int block=numRows*2-2;
        if(!block)return s;
        int blockNums=n/block;
        int rows[numRows];
        rows[0]=blockNums;
        rows[numRows-1]=blockNums;
        for(int i =1;i<numRows-1;i++){
            rows[i]=2*blockNums;
        };
        for(int i =0;i<n%block;i++){
            int rank=i<numRows?i:block-i;
            rows[rank]+=1;
        }
        char result[n+1];
        int flag=0;
        for(int i =0;i<rows[0];i++){
            result[flag++]=s.at(i*block);
        }
        for(int i =1;i<numRows-1;i++){
            for(int j =0;j<rows[i];j++){
                int rank=(j%2)?(block-i):i;
                result[flag++]=s.at(j/2*block+rank);
            }
        }
        for(int i =0;i<rows[numRows-1];i++){
            result[flag++]=s.at(i*block+numRows-1); 
        }
        result[n]='\0';
        return result;
    }
};
