class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        digits[n]+=1;
        while(n&&digits[n]>9){
            digits[n]=0;
            digits[--n]+=1;
        }
        if(digits[0]>9){
            digits[0]=0;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
