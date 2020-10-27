#include <vector>
#include <iostream>
#include <random>
#include <functional>
#include <ctime>
#include <fstream>
// #include <algorithm>
// #include <string>

using sort_fuc_t = std::function<void(std::vector<double> &, int, int, int)>;

void InsertionSort(std::vector<double> &v, int sta = 0, int end = -1)
{
    if (end == -1)
        end = v.size();
    for (int i = sta + 1; i < end; i++)
    {
        double key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void Merge(std::vector<double> &v, int sta, int mid, int end)
{
    std::vector<double> merged;
    int p1 = sta;
    int p2 = mid;

    while (p1 < mid && p2 < end)
    {
        if (v[p1] < v[p2])
            merged.push_back(v[p1++]);
        else
            merged.push_back(v[p2++]);
    }
    while (p1 < mid)
        merged.push_back(v[p1++]);
    while (p2 < end)
        merged.push_back(v[p2++]);

    std::copy_n(merged.begin(), merged.size(), v.begin() + sta);
}

void MergeSort(std::vector<double> &v, int sta = 0, int end = -1)
{
    if (end == -1)
        end = v.size();
    if (end - sta < 2)
        return;

    int mid = (sta + end) / 2;

    MergeSort(v, sta, mid);
    MergeSort(v, mid, end);
    Merge(v, sta, mid, end);
}

void HybridSort(std::vector<double> &v, int k, int sta = 0, int end = -1)
{
    if (end == -1)
        end = v.size();
    if (end - sta < 2)
        return;

    if (end - sta < k)
    {
        InsertionSort(v, sta, end);
        return;
    }

    int mid = (sta + end) / 2;

    HybridSort(v, sta, mid);
    HybridSort(v, mid, end);
    Merge(v, sta, mid, end);
}

double TimeSortFun(sort_fuc_t fun, std::vector<double> v, int k)
{
    std::clock_t start_time = std::clock();
    fun(v, k, 0, v.size());
    std::clock_t total_time = std::clock() - start_time;
    return ((double)total_time) / (double)CLOCKS_PER_SEC;
}

int main(int argc, char const *argv[])
{
    /* code */
    if (argc != 4)
    {
        std::cout << "Error: expected exactly three arguments. Format:\n"
                  << "  " << argv[0] << "[min_N] [max_N] [step]"
                  << std::endl;
    }
    size_t min_N = atoi(argv[1]);
    size_t max_N = atoi(argv[2]);
    size_t step = atoi(argv[3]);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 50000.0);

    std::ofstream out_file("hw4_2.csv");
    out_file << "N"
             << ", "
             << "20"
             << ", "
             << "40"
             << ", "
             << "60"
             << ", "
             << "80"
             << ", "
             << "100"
             << std::endl;
    int k_list_length = 7;
    int k_list[] = {20, 100, 300, 1000, 2000, 10000, 50000};
    for (size_t N = min_N; N <= max_N; N += step)
    {
        out_file << N;
        std::vector<double> v(N);
        double time_list[] = {0, 0, 0, 0, 0};
        std::cout << "HybridSort(N=" << N << ") "
                  << std::endl;
        for (int ii = 0; ii < 1; ii++)
        {
            for (auto &val : v)
            {
                val = dis(gen);
            }
            for (int k = 0; k < k_list_length; k++)
            {
                time_list[k] += TimeSortFun(HybridSort, v, k_list[k]);
            }
        }
        for (int k = 0; k < k_list_length; k++)
        {
            out_file << ", " << time_list[k];
        }
        out_file << std::endl;
    }
    return 0;
}
