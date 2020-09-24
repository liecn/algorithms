#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int n, a;
    int b;
    int flag_index;
    cin >> n;
    priority_queue<int> q;
    priority_queue<int> q_gc;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        switch (a)
        {
        case 1:
            cin >> b;
            q.push(b);
            s.push(b);
            break;
        case 2:

            q_gc.push(s.top());
            s.pop();
            break;
        case 3:
            while (q_gc.size() != 0 && (q_gc.top()==q.top()))
            {
                q.pop();
                q_gc.pop();
            }
            cout << q.top() << endl;
            break;
        }
    }
    return 0;
}