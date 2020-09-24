#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
int binarySearchForFirstGE(vector<double> &arr, int key, int low, int high)
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

int main()
{
    int n;
    double b;
    char a;
    int flag_index, size_cur;
    cin >> n;

    vector<double> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        flag_index = v.size() == 0 ? 0 : binarySearchForFirstGE(v, b, 0, v.size());
        size_cur = v.size();
        if (a == 'a')
        {
            v.insert(v.begin() + flag_index, b);
            size_cur++;
            if (size_cur % 2 == 0)
                if (abs(fmod((v[size_cur / 2] + v[size_cur / 2 - 1]), 2)) > 0.1)
                    cout << fixed<< setprecision(1) << (v[size_cur / 2] + v[size_cur / 2 - 1]) / 2 << endl;
                else
                    cout << fixed<< setprecision(0) << (v[size_cur / 2] + v[size_cur / 2 - 1]) / 2 << endl;

            else
                cout << fixed<< setprecision(0)<< v[(size_cur - 1) / 2] << endl;
        }
        else
        {
            if (size_cur != 0 && flag_index < size_cur && v[flag_index] == b)
            {
                v.erase(v.begin() + flag_index);
                size_cur--;
                if (size_cur == 0)
                    cout << "Wrong!" << endl;
                else if (size_cur % 2 == 0)
                    if (abs(fmod((v[size_cur / 2] + v[size_cur / 2 - 1]), 2)) > 0.1)
                        cout << fixed<< setprecision(1) << (v[size_cur / 2] + v[size_cur / 2 - 1]) / 2 << endl;
                    else
                        cout << fixed<< setprecision(0) << (v[size_cur / 2] + v[size_cur / 2 - 1]) / 2 << endl;
                else
                    cout << fixed<< setprecision(0)<< v[(size_cur - 1) / 2] << endl;
            }
            else
                cout << "Wrong!" << endl;
        }
    }
    return 0;
}