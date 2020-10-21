#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n,m;
    int res=0;
    string a;
    cin >> n;
    hash<string> hasher;

    // read input matrix
    vector<size_t> p_vector;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        p_vector.push_back(hasher(a));
    }
     cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a;
        vector<size_t>::iterator it=find(p_vector.begin(), p_vector.end(), hasher(a));
        if(it!=p_vector.end())
            res++;
    }

    cout << res << endl;
    return 0;
}