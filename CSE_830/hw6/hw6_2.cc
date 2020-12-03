#include <iostream>  // std::cout
#include <algorithm> // std::swap
#include <vector>    // std::vector
#include <numeric>

using namespace std;

unsigned long int nChoosek(unsigned n, unsigned k)
{
    if (k > n)
        return 0;
    if (k * 2 > n)
        k = n - k;
    if (k == 0)
        return 1;

    int result = n;
    for (int i = 2; i <= k; ++i)
    {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int main()
{
    unsigned n_node, n_edge;
    unsigned a, b;
    unsigned sum = 0;
    cin >> n_node >> n_edge;

    // read input matrix
    vector<vector<unsigned>> p_matrix;
    vector<vector<unsigned>> p_res;
    p_matrix.resize(n_node);
    p_res.resize(n_node);
    for (int i = 0; i < n_node; ++i)
    {
        p_matrix[i].resize(n_node);
        p_res[i].resize(n_node);
    }

    for (int i = 0; i < n_edge; i++)
    {
        cin >> a >> b;
        p_matrix[a][b] = 1;
        p_matrix[b][a] = 1;
    }

    for (int i = 0; i < n_node - 1; i++)
    {
        for (int j = i + 1; j < n_node; j++)
        {
            if (p_matrix[i][j] == 1)
            {
                p_res[i][j] = accumulate(p_matrix[i].begin(), p_matrix[i].end(), 0) + accumulate(p_matrix[j].begin(), p_matrix[j].end(), 0);
                int shared_node=0;
                for (int k = 0; k < n_node; k++)
                {
                    shared_node+=(p_matrix[i][k]&p_matrix[j][k]);
                }
                p_res[i][j] -=shared_node+1;
            }
        }
    }

    for (const auto &v : p_res)
    {
        for (const auto &e : v)
        {
            sum = max(sum, e);
        }
    }

    sum += nChoosek(sum, 2);

    std::cout << sum << std::endl;
}