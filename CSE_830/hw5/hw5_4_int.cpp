#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;
using ull=unsigned long long int;
int main()
{
    int n_ppl,n_skill,n_skill_required;

    cin >> n_ppl>>n_skill_required;

    string skill,skill_required,skill_zero;

    unordered_map<string,int> skill_index_map;
    map<ull,int> res;
    vector<vector<string>> person_to_skill;
    // read input matrix

    for (int i = 0; i < n_skill_required; i++)
    {
        cin >> skill;
        skill_index_map[skill]=i;
    }
    res[0]=0;
 

    for (int i = 0; i < n_ppl; i++)
    {
        // fill(skill_cur.begin(), skill_cur.end(), 0);
        vector<string> skill_cur;
        skill_cur.resize(n_skill_required);
        cin >> n_skill;
        for (int j = 0; j < n_skill; j++)
        {
            cin >> skill;
            skill_cur[j]=skill;
        }
        person_to_skill.push_back(skill_cur);
    }

    for (int i = 0; i < n_ppl; i++)
    {
        ull curr_skill = 0;
        for(int j=0;j<person_to_skill[i].size();j++)
            curr_skill |= 1<<skill_index_map[person_to_skill[i][j]];

        for(auto it = res.begin();it!=res.end();it++)
            {
                ull comb = it->first | curr_skill;
                if(res.find(comb)==res.end() || res[comb]>1+res[it->first])
                {
                    res[comb]=1+res[it->first];
                }       
            }
    }

    
    std::cout << res[(1<<n_skill_required) -1] << std::endl;
}