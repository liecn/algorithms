#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
std::vector<unsigned long long int> coins;          // Values of each coin type.

// unsigned long long int FindMinCoins(unsigned long long int value) {

//     unsigned long long int max_value=0;
//     for (auto coin : coins) {
//         if (value < coin*2 ) break;  // If the coin is too big, skip it.
//         if (value%coin!=0) continue;  // If the coin is too big, skip it.
//         unsigned long long int use_coin_count = value/coin * FindMinCoins(coin)+1;
//         if (use_coin_count > max_value) max_value = use_coin_count;
//     }
//     return max_value;
// }

unsigned long long int FindMinCoins(unsigned long long int value) {
    int n_techs=coins.size();
    std::vector<unsigned long long int> min_coins(n_techs);

    // min_coins[0] = 0;
    for (int v = 0; v < n_techs; v++) {
        unsigned long long int min_coin_count = 0;
        for (int j = 0; j < v; j++) {
            if (coins[v]%coins[j]!=0) continue;  // If the coin is too big, skip it.
            unsigned long long int use_coin_count = coins[v]/coins[j] * min_coins[j]+1;
            if (use_coin_count > min_coin_count) min_coin_count = use_coin_count;
        }     
        min_coins[v] = min_coin_count;
    }
    return min_coins.back();
}

int main()
{
    int n,n_techs;
    unsigned long long int target_val,cur_val;
    cin >> n;
    vector<unsigned long long int> p_vector;
    // read input matrix
    
    for (int i = 0; i < n; i++)
    {
        cin >> target_val>>n_techs;
        for (int i=0;i<n_techs;i++) {
            std::cin >> cur_val;
            if(cur_val*2<=target_val)coins.push_back(cur_val);
        }
        sort (coins.begin(), coins.end()); 
        coins.push_back(target_val);
        unsigned long long int res=FindMinCoins(target_val);
        coins.clear();
        p_vector.push_back(res);
    }
    for (std::vector<unsigned long long int>::const_iterator i = p_vector.begin(); i != p_vector.end(); ++i)
            cout << *i << endl;
    
}