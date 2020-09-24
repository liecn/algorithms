class Solution {
public:
    string intToRoman(int num) {
        int value[4];
        int rank=0;
        string result;
        char roman[4][4]={"IVX","XLC","CDM","M"}; 
        while(num>0){
            value[rank++]=num%10;
            num/=10;
        }
        for(int i=rank-1;i>=0;i--){
            if(value[i]<4)result.append(value[i],roman[i][0]);
            else if (value[i]>4&&value[i]<9){
                result.append(1,roman[i][1]);
                result.append(value[i]-5,roman[i][0]);
            }  
            else if (value[i]==4){
                result.append(1,roman[i][0]);
                result.append(1,roman[i][1]);
            }
            else {
                result.append(1,roman[i][0]);
                result.append(1,roman[i][2]);
            }       
        }
        return result;
    }
};
