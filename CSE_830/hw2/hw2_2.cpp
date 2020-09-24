#include <iostream>
#include <new>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // read input matrix
    long long *p = new long long[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<long long> p_vector(p, p + n);

    sort(p_vector.begin(), p_vector.end());

    long long res = LLONG_MAX;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        int count_cur = 1;
        while (i + 1 < n && p_vector[i] == p_vector[i + 1])
        {
            i++;
            count_cur++;
        }
        if (count == count_cur)
            res = min(p_vector[i], res);
        else if(count < count_cur)
        {
            res = p_vector[i];
            count = count_cur;
        }
    }
    cout << res << endl;
    return 0;
}