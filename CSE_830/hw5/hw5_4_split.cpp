#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;
using ull = unsigned long long int;
const int N = 61;

int main()
{
    int n_ppl,n_skill,n_skill_required;

    cin >> n_ppl>>n_skill_required;

    string skill;
    vector<ull> skill_std,skill_cur;
    unordered_map<string,int> skill_index_map;
    map<string,ull> res;
    string skill_zero,skill_required;

    for (int i = 0; i < n_skill_required; i++)
    {
        cin >> skill;
        skill_index_map[skill]=i;
        skill_zero.push_back('0');
        skill_required.push_back('1');
    }
    res[skill_zero]=0;
    int n_skill_std=n_skill_required/N+1;
    skill_std.resize(n_skill_std);
    skill_cur.resize(n_skill_std);

    for (int i = 0; i < n_ppl; i++)
    {
        fill(skill_std.begin(), skill_std.end(), 0);
        fill(skill_cur.begin(), skill_cur.end(), 0);
        cin >> n_skill;
        for (int j = 0; j < n_skill; j++)
        {
            cin >> skill;
            int n_skill_index=skill_index_map[skill];
            skill_std[n_skill_index/N] |= 1<<(n_skill_index%N);
        }

        for(auto it = res.begin();it!=res.end();it++)
            {
                string comb = it->first;
                
                for (int str2int_index=0;str2int_index<n_skill_std-1;str2int_index++){
                    string comb_part=comb.substr(str2int_index*N,N);
                    stringstream geek(comb_part);
                    ull x = 0; 
                    geek >> x;
                    skill_cur[str2int_index]=x;
                }
                string comb_part=comb.substr((n_skill_std-1)*N,comb.size()-(n_skill_std-1)*N);
                stringstream geek(comb_part);
                ull x = 0; 
                geek >> x;
                skill_cur[n_skill_std-1]=x;
                
                string skill_string;
                for (int int2str_index=0;int2str_index<n_skill_std;int2str_index++){
                    ull skill_ull=skill_cur[int2str_index] | skill_std[int2str_index];
                    skill_string+=to_string(skill_ull);
                }

                if(res.find(skill_string)==res.end() || res[skill_string]>1+res[it->first])
                {
                    res[skill_string]=1+res[it->first];
                }       
            }
    }

    
    std::cout << res[skill_required] << std::endl;
}