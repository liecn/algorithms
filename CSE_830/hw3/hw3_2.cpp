#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool myfunction (int i,int j) { return (i>j); }

int main()
{
    int n,m;
    int a;
    cin >> n>>m;

    // read input matrix
    vector<int> p_vector;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        p_vector.push_back(a);
    }

    sort(p_vector.begin(), p_vector.end(),myfunction);

    // for (std::vector<int>::const_iterator i = p_vector.begin(); i != p_vector.end(); ++i)
    //     std::cout << *i << ' ';
        
    int res = 0;
    int count=1;
    for (int i = 0; i < n; i+=m)
    {
        for (int j = i; j < min(i+m,n); j++)
        {
            res+=(p_vector[j]*count);
            // cout << res << endl;
        }
        count++;
    }
    cout << res << endl;
    return 0;
}