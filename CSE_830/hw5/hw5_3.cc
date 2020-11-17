#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <map>
using namespace std;

using ull=unsigned long int;
#define M 1000000009

ull FindMinCoins(vector<int> &unique_coins,int target,vector<int> &freq_vec) {
    
    vector<ull> dp(target+1);
    
    dp[0]=1;
    ull res=0;
    for (int i = unique_coins[0]; i <= target; i++)
    {
         for (int j = 0; j <unique_coins.size(); j++)
        {
            int coin=unique_coins[j];
            if (i < coin) break;        
            dp[i]+=dp[i - coin]*freq_vec[j]%M;
            
        }
    }

    return dp[target]; 
}



int main()
{
    int n;
    int n_coin,target_val;
    cin >> n;
    vector<int> coins;      
    vector<ull> p_vector; 
    // read input matrix
    
    for (int i = 0; i < n; i++)
    {
        cin >> n_coin>>target_val;
        coins.resize(n_coin);
        for (auto & coin : coins) {
            std::cin >> coin;
        }
        sort(coins.begin(),coins.end());
        map<int,int> freq_map;
        vector<int> freq_vec;
        for(int i : coins)
            ++freq_map[i];
        
        for (map<int, int>::iterator it = freq_map.
        begin(); it != freq_map.end(); it++ )
        {
           freq_vec.push_back(it->second);  
        }

        coins.erase(unique(coins.begin(),coins.end()),coins.end());

        ull res=FindMinCoins(coins,target_val,freq_vec);
        p_vector.push_back(res);
    }
    for (vector<ull>::const_iterator i = p_vector.begin(); i != p_vector.end(); ++i)
            cout << *i % M << endl;
    
}