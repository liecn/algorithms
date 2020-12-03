#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector

using namespace std;

unsigned long int nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main()
{
    unsigned n_node,n_edge;
    unsigned a,b;
    unsigned long int sum=0;
    cin >> n_node>>n_edge;

    // read input matrix
    vector<unsigned long int> p_vector;
    p_vector.resize(n_node);

    for (int i = 0; i < n_edge; i++)
    {
        cin >> a>>b;
        p_vector[a]++;
        p_vector[b]++;
    }

    sum+=*max_element(p_vector.begin(), p_vector.end());

    sum+=nChoosek(sum,2);
    
    std::cout << sum << std::endl;
}