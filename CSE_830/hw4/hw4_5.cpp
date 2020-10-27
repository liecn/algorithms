#include <iostream>
#include <new>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

unsigned int countSetBits(unsigned long long n) 
{ 
    unsigned int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

int main()
{
    int n;
    unsigned long long a,b;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout<<countSetBits(a-b)<<endl;
    }
    return 0;
}