#include <iostream>
#include <new>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

void printQueue(priority_queue <int, vector<int>, greater<int> > q){
    if (q.empty()) return;
    else {
        int a=q.top();
        q.pop();
        printQueue(q);
        cout << a<<endl;
    }
}

int main()
{
    int n, m;
    int a;
    int counter=0;
    priority_queue <int, vector<int>, greater<int> > q;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a;
        q.push(a);
    }

    for (int i = 0; i < n-m; i++)
    {
        cin >> a;
        if (a>q.top()){
            q.pop();
            q.push(a);
        }
    }
    printQueue(q);
    return 0;
}