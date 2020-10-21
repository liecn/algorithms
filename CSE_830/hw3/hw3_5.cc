#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    int a;
    cin >> n>>m;

    // read input matrix
    vector<int> p_vector;

    for (int i = 0; i < m; i++)
    {
        cin >> a;
        p_vector.push_back(a);
    }

    sort(p_vector.begin(), p_vector.end());

    // for (std::vector<int>::const_iterator i = p_vector.begin(); i != p_vector.end(); ++i)
    //     std::cout << *i << ' ';
    int res=*p_vector.begin();
    for (vector<int>::iterator it=p_vector.begin(); it<p_vector.end()-1; it++)
    {
        int x=*(it+1);
        int y=*it;

        int dis_new=(x-y)/2;
        if(dis_new>res){
            res=dis_new;
        }
    }
    int dis_new=n-p_vector.back()-1;
    if(dis_new>res){
        res=dis_new;
    }
    cout << res << endl;
    return 0;
}