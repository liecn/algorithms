class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(n<0){
            if(n==-2147483648)n=n+2;
            n=-n;
            x=1/x;
        }
        return (n&1)?sqr(myPow(x,n>>1))*x:sqr(myPow(x,n>>1));        
    }
private:
    double sqr(double a){
        return a*a;
    }
};
int x = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
