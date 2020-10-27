#include <vector>
#include <iostream>
#include <random>
#include <functional>
#include <ctime>
#include <fstream>
#include <map>
#include <unordered_map>

using sort_fuc_t = std::function<void(std::vector<int> &, int, int, int)>;

void MultimapInsertion(std::vector<int> &v, int k, int sta = 0, int end = -1)
{
    if (end == -1)
        end = v.size();
    std::multimap<int, int> multimap;

    for (int i = sta; i < end; i++)
    {
        multimap.insert(std::pair<int, int>(v[i] % k, v[i]));
    }
}

void UnorderedMultimapInsertion(std::vector<int> &v, int k, int sta = 0, int end = -1)
{
    if (end == -1)
        end = v.size();
    std::unordered_multimap<int, int> my_unordered_multimap;

    for (int i = sta; i < end; i++)
    {
        my_unordered_multimap.insert(std::pair<int, int>(v[i] % k, v[i]));
    }
}

double TimeSortFun(sort_fuc_t fun, std::vector<int> v, int k)
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
    std::uniform_int_distribution<> dis(0, 50000);

    std::ofstream out_file("hw4_3.csv");
    out_file << "N"
             << ", "
             << "Multimap_tree_based"
             << ", "
             << "unordered_multimap_hash_table"
             << std::endl;
    int k_size = 500;
    for (size_t N = min_N; N <= max_N; N += step)
    {
        out_file << N;
        std::vector<int> v(N);
        std::cout << "MapInsertion(N=" << N << ") "
                  << std::endl;
        double run_time_multimap = 0;
        double run_time_unordered_multimap = 0;
        for (int ii=0;ii<10;ii++){
            for (auto &val : v)
            {
                val = dis(gen);
            }

            run_time_multimap += TimeSortFun(MultimapInsertion, v, k_size);
            run_time_unordered_multimap += TimeSortFun(UnorderedMultimapInsertion, v, k_size);
        }

        out_file << ", " << run_time_multimap << ", " << run_time_unordered_multimap;

        out_file << std::endl;
    }
    return 0;
}
