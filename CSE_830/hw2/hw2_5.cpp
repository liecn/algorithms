#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct task
{
    int arrivingTime;
    int duration;
};

bool compareByArrivingTime(const task &a, const task &b)
{
    return a.arrivingTime < b.arrivingTime;
}
bool compareByDuration(const task &a, const task &b)
{
    return a.duration < b.duration;
}

int binarySearchForFirstGE(vector<task> &arr, int key, int low, int high)
{
    int sta = low, end = high - 1;
    while (sta <= end)
    {
        int mid = (sta + end) / 2;
        if (arr[mid].arrivingTime < key)
            sta = mid + 1;
        else if (arr[mid].arrivingTime >= key)
            end = mid - 1;
    }
    return end + 1;
}

int main()
{
    int n;
    int a, b;
    long long res, clock;

    int flag_index = 1;
    int flag_index_update = 1;
    cin >> n;
    vector<task> v;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), compareByArrivingTime);
    res = v[0].duration;
    clock = v[0].arrivingTime + v[0].duration;
    for (int i = 1; i < n; i++)
    {
        flag_index_update = max(i, flag_index);
        flag_index = binarySearchForFirstGE(v, clock, flag_index_update, v.size());
        if (flag_index != flag_index_update)
            sort(v.begin() + i, v.begin() + flag_index, compareByDuration);
        if (clock < v[i].arrivingTime)
        {
            res += v[i].duration;
            clock = v[i].arrivingTime + v[i].duration;
        }
        else
        {
            res += v[i].duration + clock - v[i].arrivingTime;
            clock += v[i].duration;
        }
    }
    cout << fixed << setprecision(0) << floor(res / n) << endl;
    return 0;
}