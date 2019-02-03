class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mapRoman;
        int it1;
        int it2;
        int n=s.length();
        mapRoman['I']=1   ;
        mapRoman['V']=5   ;
        mapRoman['X']=10  ;
        mapRoman['L']=50  ;
        mapRoman['C']=100 ;
        mapRoman['D']=500 ;
        mapRoman['M']=1000;     
        int result=0; 
        for(int i=n-1;i>0;i--){
            it1 = mapRoman.find(s.at(i))->second;
            it2 = mapRoman.find(s.at(i-1))->second;
            if(it1>it2){
                result+=it1-it2;
                i--;
            }
            else result+=it1;        
        }
        if(n==1||mapRoman.find(s.at(0))->second>=mapRoman.find(s.at(1))->second)result+=mapRoman.find(s.at(0))->second;
        return result;
    }
};
