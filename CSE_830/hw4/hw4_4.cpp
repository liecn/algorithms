#include <iostream>
#include <new>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{   
    int n,k;
    cin >> n >> k;
    // read input matrix
    int *p = new int[n];
    string s;
    cin>>s;
    int s_length=s.length();
    p[n-1]=int(s[s_length-1])-48;
    for(int i=1;i<n;i++){
        p[n-1-i]=abs(int(s[s_length-i-1])-int(s[s_length-i]));
    }
    cout<<endl;
    for(int i=k+1;i<n+1;i++){
        p[n-i]=abs(p[n-i]-p[n-i+k]);
    }
    for(int i=0;i<n;i++){
        cout << p[i];
    }
    cout<<endl;
    return 0;
}