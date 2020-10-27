#include <vector>
#include <iostream>
#include <random>
#include <functional>
#include <ctime>
#include <fstream>
// #include <algorithm>
// #include <string>

using sort_fuc_t = std::function<void(std::vector<double> &, int, int)>;

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
        v[j+1] = key;
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

void DividedInsertionSort(std::vector<double> &v, int sta = 0, int end = -1)
{
    if (end == -1)
        end = v.size();
    if (end - sta < 2)
        return;

    int mid = (sta + end) / 2;

    InsertionSort(v, sta, mid);
    InsertionSort(v, mid, end);
    Merge(v, sta, mid, end);
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

void HybridSort(std::vector<double> &v, int sta = 0, int end = -1)
{
    if (end == -1)
        end = v.size();
    if (end - sta < 2)
        return;

    if (end - sta < 20)
    {
        InsertionSort(v, sta, end);
        return;
    }

    int mid = (sta + end) / 2;

    HybridSort(v, sta, mid);
    HybridSort(v, mid, end);
    Merge(v, sta, mid, end);
}

double TimeSortFun(sort_fuc_t fun, std::vector<double> v)
{
    std::clock_t start_time = std::clock();
    fun(v, 0, v.size());
    std::clock_t total_time = std::clock() - start_time;
    return ((double)total_time) / (double)CLOCKS_PER_SEC;
}

void PrintVector(const std::vector<double> &v, size_t max = (size_t)-1)
{
    for (size_t i = 0; i < max && i < v.size(); i++)
    {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
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
    std::uniform_real_distribution<> dis(0.0, 1000.0);

    std::ofstream out_file("output.csv");

    for (size_t N = min_N; N <= max_N; N += step)
    {
        out_file << N;
        std::vector<double> v(N);
        for (auto &val : v)
        {
            val = dis(gen);
        }

        std::vector<double> v_best(N);
        std::vector<double> v_worst(N);
        for (int i = 0; i < N; i++)
        {
            v_best[i] = (double)i;
            v_worst[i] = (double)N - i;
        }

        // Collect data on using InsertionSort.
        double run_time = TimeSortFun(InsertionSort, v);
        double run_time_best = TimeSortFun(InsertionSort, v_best);
        double run_time_worst = TimeSortFun(InsertionSort, v_worst);
        std::cout << "InsertionSort(N=" << N << ") "
                  << "best_time=" << run_time_best << "s"
                  << "rand_time=" << run_time << "s"
                  << "worst_time=" << run_time_worst << "s"
                  << std::endl;
        out_file << ", " << run_time_best
                 << ", " << run_time
                 << ", " << run_time_worst;
        
        // Collect data on using DividedInsertionSort.
        // run_time = TimeSortFun(DividedInsertionSort, v);
        // run_time_best = TimeSortFun(DividedInsertionSort, v_best);
        // run_time_worst = TimeSortFun(DividedInsertionSort, v_worst);
        // std::cout << "DividedInsertionSort(N=" << N << ") "
        //           << "best_time=" << run_time_best << "s"
        //           << "rand_time=" << run_time << "s"
        //           << "worst_time=" << run_time_worst << "s"
        //           << std::endl;
        // out_file << ", " << run_time_best
        //          << ", " << run_time
        //          << ", " << run_time_worst;

        // Collect data on using MergeSort.
        run_time = TimeSortFun(MergeSort, v);
        run_time_best = TimeSortFun(MergeSort, v_best);
        run_time_worst = TimeSortFun(MergeSort, v_worst);
        std::cout << "MergeSort(N=" << N << ") "
                  << "best_time=" << run_time_best << "s"
                  << "rand_time=" << run_time << "s"
                  << "worst_time=" << run_time_worst << "s"
                  << std::endl;
        out_file << ", " << run_time_best
                 << ", " << run_time
                 << ", " << run_time_worst;

        // Collect data on using HybridSort.
        // run_time = TimeSortFun(HybridSort, v);
        // run_time_best = TimeSortFun(HybridSort, v_best);
        // run_time_worst = TimeSortFun(HybridSort, v_worst);
        // std::cout << "HybridSort(N=" << N << ") "
        //           << "best_time=" << run_time_best << "s"
        //           << "rand_time=" << run_time << "s"
        //           << "worst_time=" << run_time_worst << "s"
        //           << std::endl;
        // out_file << ", " << run_time_best
        //          << ", " << run_time
        //          << ", " << run_time_worst;

        out_file << std::endl;

        // std::cout << "Unsorted: ";
        // PrintVector(v);
        // std::cout << std::endl;

        // InsertionSort(v);

        // std::cout << "Sorted:   ";
        // PrintVector(v);
        // std::cout << std::endl;
    }
    return 0;
}
