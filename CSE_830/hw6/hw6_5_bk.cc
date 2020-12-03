#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bitset>

using namespace std;

#define M 200

struct node
{
    int node_importance;
    bitset<M> edge_list;
};

// bool n_skill_sorter(person const& lhs, person const& rhs) {
//     return lhs.skill_list.count() > rhs.skill_list.count();
// }

bool importance_sorter(node const &lhs, node const &rhs)
{
    return lhs.node_importance > rhs.node_importance;
}

int main()
{
    int n_node, n_edges, n_node_important;

    cin >> n_node >> n_edges >> n_node_important;

    bitset<M> node_zero(0), node_ans(0);
    unordered_map<bitset<M>, bool> res;
    res.reserve(1 << 14);
    vector<node> node_list;
    vector<int> node_value(1);
    
    node_list.resize(n_node);

    // res[node_zero] = 1;
    
    for (int i = 0; i < n_node; i++)
    {
        node_list[i].edge_list = node_zero;
    }
    
    int a, b;
    for (int i = 0; i < n_edges; i++)
    {
        cin >> a >> b;
        node_list[a].edge_list.set(b);
        node_list[b].edge_list.set(a);
    }
    // res[node_list[0].edge_list] = 1;

    //record the person
    for (int i = 0; i < n_node_important; i++)
    {
        cin >> a;
        node_value[a] = 10;
        node_ans.set(a);
    }

    // res[node_ans.to_string()] = M;

    // cout << "node_ans: " << node_ans << endl;

    for (int i = 0; i < n_node; i++)
    {
        node_list[i].node_importance = node_list[i].edge_list.count();
        for (int j = 0; j < n_node; j++)
        {
            node_list[i].node_importance += node_value[j] * node_list[i].edge_list.test(j);
        }
    }

    // cout<<"node_info: ";
    // for (vector<node>::const_iterator i = node_list.begin(); i != node_list.end(); ++i)
    //         cout << (*i).node_importance <<' '<<(*i).edge_list<<' ';
    // cout<<endl;

    sort(node_list.begin(), node_list.end(), &importance_sorter);

    // cout<<"sorted node_info: ";
    // for (vector<node>::const_iterator i = node_list.begin(); i != node_list.end(); ++i)
    //         cout << (*i).node_importance <<' '<<(*i).edge_list<<' ';
    // cout<<endl;

    // filter the person with repeated skills
    // for (int i = 1; i < n_ppl; i++)
    // {
    //     // person_important[i]=1;
    //     for (int j = 0; j < i; j++)
    //     {
    //         bitset<M> shared_skill = person_to_skill[j].skill_list & person_to_skill[i].skill_list;
    //         if (shared_skill.count() == person_to_skill[i].skill_list.count())
    //         {
    //             person_to_skill[i].person_importance = 0;
    //             break;
    //         }
    //     }
    // }

    // cout<<"person_repeated: ";
    // for (vector<person>::const_iterator i = person_to_skill.begin(); i != person_to_skill.end(); ++i)
    //         cout << (*i).person_importance <<' ';
    // cout<<endl;

    // for (int i = 0; i < n_ppl; i++)
    // {
    //     if (!person_to_skill[i].person_importance)
    //         continue;
    //     for (int j = 0; j < n_skill_required; j++)
    //     {
    //         if (person_to_skill[i].skill_list.test(j))
    //             skill_importance[j]++;
    //     }
    // }

    // cout<<"skill_importance: ";
    // for (vector<int>::const_iterator i = skill_importance.begin(); i != skill_importance.end(); ++i)
    //         cout << *i <<' ';
    // cout<<endl;

    //ensured person
    // int person_ensured = 0;
    // for (int i = 0; i < n_ppl; i++)
    // {
    //     if (!person_to_skill[i].person_importance)
    //         continue;
    //     bitset<M> skill_list_cur_person = person_to_skill[i].skill_list;
    //     for (int j = 0; j < n_skill_required; j++)
    //     {
    //         if (skill_list_cur_person.test(j) && skill_importance[j] == 1)
    //         {
    //             for (int k = 0; k < n_skill_required; k++)
    //             {
    //                 if (skill_list_cur_person.test(k))
    //                     skill_importance[k] = 0;
    //             }
    //             person_to_skill[i].person_importance = 0;
    //             person_ensured++;
    //             // cout<<"skill_importance: "<<i<<":";
    //             // for (vector<int>::const_iterator i = skill_importance.begin(); i != skill_importance.end(); ++i)
    //             //         cout << *i <<' ';
    //             // cout<<endl;
    //         }
    //         if (!person_to_skill[i].person_importance)
    //             break;
    //     }
    // }
    // for (size_t i = 0; i < n_skill_required; i++)
    // {
    //     if (skill_importance[i])
    //         continue;
    //     skill_required.reset(i);
    //     for (size_t j = 0; j < n_ppl; j++)
    //     {
    //         if (person_to_skill[j].person_importance)
    //             person_to_skill[j].skill_list.reset(i);
    //     }
    // }

    // cout<<"Ensured number: "<<person_ensured<<endl;

    // for (int i = 0; i < n_ppl; i++)
    // {
    //     if (!person_to_skill[i].person_importance)
    //         continue;
    //     for (int j = 0; j < n_skill_required; j++)
    //     {
    //         if (person_to_skill[i].skill_list.test(j) && skill_importance[j])
    //             person_to_skill[i].person_importance += (100 / skill_importance[j]);
    //     }
    // }

    // sort(person_to_skill.begin(), person_to_skill.end(), &importance_sorter);

    // cout<<"person_importance: ";
    // for (vector<person>::const_iterator i = person_to_skill.begin(); i != person_to_skill.end(); ++i)
    //         cout << (*i).person_importance <<' ';
    // cout<<endl;

    // skill_required_string = skill_required.to_string();

    // int min_ans=0,skill_counted=0;
    // for (size_t i = 0; i < n_ppl && skill_counted<n_skill_required; i++)
    // {
    //     if (!person_to_skill[i].person_importance) break;
    //     skill_counted+=person_to_skill[i].skill_list.count();
    //     min_ans++;
    // }
    // cout<<"Minimal number: "<<min_ans<<endl;

    // cout<<"skill_required_string: "<<skill_required_string<<endl;

    for (int i = 0; i < n_node; i++)
    {
        // if (!node_list[i].node_importance)
        //     break;

        node_zero = node_list[i].edge_list;
        if (res.find(node_zero) == res.end() || res[node_zero] ==0)
            res[node_zero] = 1;
        for (auto it = res.begin(); it != res.end(); it++)
        {
            bitset<M> existing(it->first);
            bitset<M> comb_combined = existing | node_zero;

            int res_count = res[it->first];
            if (res.find(comb) == res.end() || res[comb] > 1 + res_count)
            {
                // if (res[skill_required_string]==min_ans){
                //      std::cout << min_ans+person_ensured << std::endl;
                //      return 0;
                // }
                res[comb] = 1 + res_count;
            }
        }
    }

    int ans = M;
    for (auto it = res.begin(); it != res.end(); it++)
    {
        bitset<M> comb(it->first);
        comb &= node_ans;
        if (comb.count() >= n_node_important && ans > res[it->first])
            ans = res[it->first];
    }

    std::cout << ans+n_node_important << std::endl;
}