#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    int n_ppl,n_skill,n_skill_required;

    cin >> n_ppl>>n_skill_required;

    string skill,skill_required,skill_zero;
    vector<int> skill_cur;
    unordered_map<string,int> skill_index_map;
    map<string,int> res;
    vector<vector<int>> person_to_skill;
    // read input matrix

    for (int i = 0; i < n_skill_required; i++)
    {
        cin >> skill;
        skill_index_map[skill]=i;
        skill_required.push_back('1');
        skill_zero.push_back('0');
    }
    res[skill_zero]=0;
    skill_cur.resize(n_skill_required);

    for (int i = 0; i < n_ppl; i++)
    {
        fill(skill_cur.begin(), skill_cur.end(), 0);
        cin >> n_skill;
        for (int j = 0; j < n_skill; j++)
        {
            cin >> skill;
            skill_cur[skill_index_map[skill]]=1;
        }
        person_to_skill.push_back(skill_cur);
    }

    for (int i = 0; i < n_ppl; i++)
    {
        skill_cur=person_to_skill[i];

        for(auto it = res.begin();it!=res.end();it++)
            {
                string comb = it->first;
                for (int s=0;s<comb.size();s++){
                    if (comb[s]=='0')
                        comb[s] = '0' + skill_cur[s];
                };
                if(res.find(comb)==res.end() || res[comb]>1+res[it->first])
                {
                    res[comb]=1+res[it->first];
                }       
            }
    }

    
    std::cout << res[skill_required] << std::endl;
}