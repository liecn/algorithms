#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>

using namespace std;

#define M 200

struct person {
  int person_importance;
  bitset<M> skill_list;
};

bool n_skill_sorter(person const& lhs, person const& rhs) {
    return lhs.skill_list.count() > rhs.skill_list.count();
}

bool importance_sorter(person const& lhs, person const& rhs) {
    return lhs.person_importance > rhs.person_importance;
}

int main()
{
    int n_ppl,n_skill,n_skill_required;

    cin >> n_ppl>>n_skill_required;

    string skill,skill_required_string;
    bitset<M> skill_required,skill_zero(0);
    unordered_map<string,int> skill_index_map;
    unordered_map<string,int> res;
    res.reserve(1<<14);
    vector<person> person_to_skill;
    vector<int> skill_importance;
    
    // map the skill to int
    person_to_skill.resize(n_ppl);
    skill_importance.resize(n_skill_required);
    res[skill_zero.to_string()]=0;

    for (int i = 0; i < n_skill_required; i++)
    {
        cin >> skill;
        skill_index_map[skill]=i;
        skill_required.set(i);
    }

    //record the person
    for (int i = 0; i < n_ppl; i++)
    {
        skill_zero.reset();
        cin >> n_skill;
        for (int j = 0; j < n_skill; j++)
        {
            cin >> skill;
            skill_zero.set(skill_index_map[skill]);
        }
        person_to_skill[i].person_importance=1;
        person_to_skill[i].skill_list=skill_zero;
    }
    sort(person_to_skill.begin(), person_to_skill.end(), &n_skill_sorter);
    
    // filter the person with repeated skills
    for (int i=1;i<n_ppl;i++){
        // person_important[i]=1;
        for (int j=0;j<i;j++){
            bitset<M> shared_skill=person_to_skill[j].skill_list & person_to_skill[i].skill_list;
            if(shared_skill.count()==person_to_skill[i].skill_list.count()){
                person_to_skill[i].person_importance=0;
                break;
            }
        }
    }

    // cout<<"person_repeated: ";
    // for (vector<person>::const_iterator i = person_to_skill.begin(); i != person_to_skill.end(); ++i)
    //         cout << (*i).person_importance <<' ';
    // cout<<endl;

    for (int i=0;i<n_ppl;i++){
        if (!person_to_skill[i].person_importance) continue;
        for (int j=0;j<n_skill_required;j++){
            if (person_to_skill[i].skill_list.test(j)) skill_importance[j]++;
        }
    }

    // cout<<"skill_importance: ";
    // for (vector<int>::const_iterator i = skill_importance.begin(); i != skill_importance.end(); ++i)
    //         cout << *i <<' ';
    // cout<<endl;

    //ensured person
    int person_ensured=0;
    for (int i=0;i<n_ppl;i++){
        if (!person_to_skill[i].person_importance) continue;
        bitset<M> skill_list_cur_person=person_to_skill[i].skill_list;
        for (int j=0;j<n_skill_required;j++){
            if (skill_list_cur_person.test(j) && skill_importance[j]==1) {
                for (int k=0;k<n_skill_required;k++){
                    if (skill_list_cur_person.test(k))skill_importance[k]=0;
                }
                person_to_skill[i].person_importance=0;
                person_ensured++;
                // cout<<"skill_importance: "<<i<<":";
                // for (vector<int>::const_iterator i = skill_importance.begin(); i != skill_importance.end(); ++i)
                //         cout << *i <<' ';
                // cout<<endl;
            }
            if (!person_to_skill[i].person_importance) break;
        }
    }
    for (size_t i = 0; i < n_skill_required; i++)
    {
        if (skill_importance[i]) continue;
        skill_required.reset(i);
        for (size_t j = 0; j < n_ppl; j++)
        {
            if(person_to_skill[j].person_importance)
            person_to_skill[j].skill_list.reset(i);
        }
        
    }
    

    // cout<<"Ensured number: "<<person_ensured<<endl;

   for (int i=0;i<n_ppl;i++){
        if (!person_to_skill[i].person_importance) continue;
        for (int j=0;j<n_skill_required;j++){
            if (person_to_skill[i].skill_list.test(j)&&skill_importance[j]) person_to_skill[i].person_importance+=(100/skill_importance[j]);
        }
    }

    sort(person_to_skill.begin(), person_to_skill.end(), &importance_sorter);
    
    // cout<<"person_importance: ";
    // for (vector<person>::const_iterator i = person_to_skill.begin(); i != person_to_skill.end(); ++i)
    //         cout << (*i).person_importance <<' ';
    // cout<<endl;

    skill_required_string=skill_required.to_string();

    // int min_ans=0,skill_counted=0;
    // for (size_t i = 0; i < n_ppl && skill_counted<n_skill_required; i++)
    // {
    //     if (!person_to_skill[i].person_importance) break;
    //     skill_counted+=person_to_skill[i].skill_list.count();
    //     min_ans++;
    // }
    // cout<<"Minimal number: "<<min_ans<<endl;

    // cout<<"skill_required_string: "<<skill_required_string<<endl;

    for (int i = 0; i < n_ppl; i++)
    {
        if (!person_to_skill[i].person_importance) break;

        skill_zero=person_to_skill[i].skill_list;

        for(auto it = res.begin();it!=res.end();it++)
        {
            bitset<M> comb (it->first); 
            comb |= skill_zero;

            string skill_list=comb.to_string();
            int res_count=res[it->first];
            if(res.find(skill_list)==res.end() || res[skill_list]>1+res_count)
            {
                // if (res[skill_required_string]==min_ans){
                //      std::cout << min_ans+person_ensured << std::endl;
                //      return 0;
                // }
                res[skill_list]=1+res_count;
            } 
            
        }
    }

    
    std::cout << res[skill_required_string]+person_ensured << std::endl;
}