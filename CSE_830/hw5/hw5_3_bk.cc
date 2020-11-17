#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <unordered_map>
using namespace std;

using ull=unsigned long int;
#define M 1000000009

ull FindMinCoins(vector<int> &unique_coins,int target,unordered_map<int,int> &freq_map,int inc_space) {
    
    vector<ull> dp(target+1-unique_coins[0]);
    
    dp[0]=1;
    ull res=0;
    for (int i = unique_coins[0]; i <= target-unique_coins[0]; i+=inc_space)
    {
        for (const auto & coin : unique_coins)
        {
            if (i < coin) break;        
            dp[i]+=dp[i - coin]*freq_map[coin]%M;
            
        }
    }

    for (const auto & coin : unique_coins)
    {
        if (target < coin) break;        
        res+=dp[target - coin]*freq_map[coin]%M;
            
    }

    return res; 
}

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
int findGCD(vector<int> arr, int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
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
        unordered_map<int,int> freq_map;
        for(int i : coins)
        ++freq_map[i];

        coins.erase(unique(coins.begin(),coins.end()),coins.end());

        int inc_space=findGCD(coins,n_coin);
        cout<<"!!!:"<<inc_space<<endl;
        ull res=FindMinCoins(coins,target_val,freq_map,inc_space);
        p_vector.push_back(res);
    }
    for (vector<ull>::const_iterator i = p_vector.begin(); i != p_vector.end(); ++i)
            cout << *i % M << endl;
    
}