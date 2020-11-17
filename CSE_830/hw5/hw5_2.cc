#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
std::vector<int> coins;          // Values of each coin type.

int FindMinCoins(int value) {

    int max_value=0;
    if (value<=0) return max_value;
    for (auto coin : coins) {
        if (coin > value) continue;  // If the coin is too big, skip it.
        if (value%coin==0) return value;  // If the coin is too big, skip it.
        int use_coin_count = coin + FindMinCoins(value-coin);
        if (use_coin_count > max_value) max_value = use_coin_count;
    }
    return max_value;
}

bool myfunction (int i,int j) { return (i>j); }

int main()
{
    int n;
    int n_coin,max_val;
    cin >> n;
    vector<int> p_vector;
    // read input matrix
    
    for (int i = 0; i < n; i++)
    {
        cin >> n_coin>>max_val;
        coins.resize(n_coin);
        for (auto & coin : coins) {
            std::cin >> coin;
        }
        sort (coins.begin(), coins.end(), myfunction); 
        int res=FindMinCoins(max_val);
        p_vector.push_back(res);
    }
    for (std::vector<int>::const_iterator i = p_vector.begin(); i != p_vector.end(); ++i)
            cout << *i << endl;
    
}