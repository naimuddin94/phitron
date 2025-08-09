#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int pos;
    cin >> pos;

    priority_queue<int> pq;

    for (int it : v)
    {
        pq.push(it);
    }

    while (--pos)
    {
        if (!pq.empty())
        {
            pq.pop();
        }
    }

    if (!pq.empty())
    {
        cout << pq.top() << endl;
    }

    return 0;
}