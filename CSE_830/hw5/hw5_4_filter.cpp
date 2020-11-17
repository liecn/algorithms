#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

struct person {
  int n_skill;
  vector<int> skill_list;
};

bool person_sorter(person const& lhs, person const& rhs) {
    return lhs.n_skill > rhs.n_skill;
}

bool person_can_be_ignored(vector<int> const& lhs, vector<int> const& rhs) {
    for (int i=0;i<lhs.size();i++){
        if(lhs[i] < rhs[i] ) return false;
    }
    return true;
}
vector<int> person_to_be_merged(vector<int> const& lhs, vector<int> const& rhs) {
    vector<int> new_skill_list=lhs;
    for (int i=0;i<lhs.size();i++){
        new_skill_list[i]|=rhs[i];
    }
    return new_skill_list;
}

int main()
{
    int n_ppl,n_skill,n_skill_required;

    cin >> n_ppl>>n_skill_required;

    string skill,skill_required,skill_zero;
    vector<int> skill_cur;
    unordered_map<string,int> skill_index_map;
    map<string,int> res;
    vector<person> person_to_skill;
    vector<int> person_important;
    
    // read input matrix

    for (int i = 0; i < n_skill_required; i++)
    {
        cin >> skill;
        skill_index_map[skill]=i;
        skill_required.push_back('1');
        skill_zero.push_back('0');
    }
    res[skill_zero]=0;
    // skill_cur.resize(n_skill_required);
    
    for (int i = 0; i < n_ppl; i++)
    {
        // fill(skill_cur.begin(), skill_cur.end(), 0);
        person new_person;
        new_person.skill_list.resize(n_skill_required);
        cin >> n_skill;
        new_person.n_skill=n_skill;
        for (int j = 0; j < n_skill; j++)
        {
            cin >> skill;
            new_person.skill_list[skill_index_map[skill]]=1;
        }
        
        person_to_skill.push_back(new_person);
        person_important.push_back(1);
    }

    sort(person_to_skill.begin(), person_to_skill.end(), &person_sorter);
    int bbb=0;
    vector<int> existing_skill=person_to_skill[0].skill_list;
    for (int i=1;i<n_ppl;i++){
        if(person_can_be_ignored(existing_skill,person_to_skill[i].skill_list)){
            person_important[i]=0;
            bbb++;
        }
        // else 
        // existing_skill=person_to_be_merged(existing_skill,person_to_skill[i].skill_list);
    }
    // cout<<bbb<<endl;
    for (int i = 0; i < n_ppl; i++)
    {
        if(person_important[i]){
            skill_cur=person_to_skill[i].skill_list;

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
    }

    
    std::cout << res[skill_required] << std::endl;
}