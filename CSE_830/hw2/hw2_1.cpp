#include <iostream>
#include <new>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    int a, b;
    cin >> n;

    // read input matrix
    int *p = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        p[i] = a - b;
    }

    int i,j = 0;
    for (i = 0; i < n; i++)
    {
        int sum = 0;
        int add_index=i;
        for (j = 0; j < n; j++)
        {
            sum+=p[add_index%n];
            add_index+=1;
            if (sum<0) break;
        }
        if (j==n) break;
    }
    cout << i <<endl;
    delete[] p;
    return 0;
}