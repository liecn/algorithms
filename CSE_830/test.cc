#include <iostream>
#include <new>
#include <string>
#include <algorithm>

using namespace std;
int binarySearch(vector<int> &arr, int key, int low, int high)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, key, (mid + 1), high);
    return binarySearch(arr, key, low, (mid - 1));
}

int binarySearchForFirstGE(vector<int> &arr, int key, int low, int high)
{
    int sta = 0, end = high - 1;
    while (sta <= end)
    {
        int mid = (sta + end) / 2;
        if (arr[mid] < key)
            sta = mid + 1;
        else if (arr[mid] >= key)
            end = mid - 1;
    }
    return end + 1;
}

void PrintMatrix(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// flag_index = v.size() == 0 ? 0 : binarySearchForFirstGE(v, s.top(), 0, v.size());
// v.insert(v.begin() + flag_index, s.top());

// for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
//     std::cout << *i << ' ';
// cout << endl;
int main()
{
    int n, m;
    cin >> m >> n;

    // read input matrix
    int **p = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }
    PrintMatrix(p, m, n);

    for (std::vector<int>::const_iterator i = p_vector.begin(); i != p_vector.end(); ++i)
        std::cout << *i << ' ';

    // PrintMatrix(p,m,n);
    //find the optimal two plus which are not overlap
    for (int i = 0; i < m; i++)
    {
    }
    delete[] p;
    return 0;
}