#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// template <class ForwardIterator>
// vector<int>::iterator is_sorted_cus (ForwardIterator first, ForwardIterator last)
// {
//   if (first==last) return last;
//   ForwardIterator next = first;
//   while (++next!=last) {
//     if (*next<*first)     // or, if (comp(*next,*first)) for version (2)
//       return next;
//     ++first;
//   }
//   return last;
// }


int main()
{
    int n;
    int a;
    cin >> n;

    // read input matrix
    vector<int> p_vector;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        p_vector.push_back(a);
    }
    vector<int>::iterator flag_1,flag_2;

    int count=0;
    for (vector<int>::iterator it=p_vector.begin(); it<p_vector.end()-1; it++){
        if (*it>*(it+1)){
            if(count==0) flag_1=it;
            count++;
            flag_2=it;
        }
    }

    if(count==0)
    cout << "yes" << endl;
    else if(count==1){
        swap(*flag_1,*(flag_1+1));
        if (is_sorted(p_vector.begin(),p_vector.end())){
            cout << "yes" << endl;
            cout << "swap " << int(flag_1-p_vector.begin())+1<<" "<< int(flag_1-p_vector.begin())+2<<endl;
        }
        else cout << "no" << endl;
    }
    else if(count==2){
        flag_2++;
        swap(*flag_1,*flag_2);
        if (is_sorted(p_vector.begin(),p_vector.end())){
            cout << "yes" << endl;
            cout << "swap " << int(flag_1-p_vector.begin())+1<<" "<< int(flag_2-p_vector.begin())+1<<endl;
        }
        else cout << "no" << endl;
    }
    else{
        flag_2=flag_2+2;
        reverse(flag_1,flag_2);
        if (is_sorted(p_vector.begin(),p_vector.end())){
            cout << "yes" << endl;
            cout << "reverse " << int(flag_1-p_vector.begin())+1<<" "<< int(flag_2-p_vector.begin())<<endl;
        }
        else cout << "no" << endl;
    }
   
    // for (std::vector<int>::const_iterator i = p_vector.begin(); i != p_vector.end(); ++i)
    //     std::cout << *i << ' ';       
    return 0;
}