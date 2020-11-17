#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector

using namespace std;
int main()
{
    int n;
    unsigned long int a;
    unsigned long int cur=0,sum=0;
    cin >> n;

    // read input matrix
    vector<unsigned long int> p_vector;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        p_vector.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        cur=max(sum,cur+p_vector[i]);
        swap(cur,sum);
    }
    
    std::cout << sum << std::endl;
}