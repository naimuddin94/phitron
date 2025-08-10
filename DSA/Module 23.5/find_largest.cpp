#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty())
    {
        int first = pq.top();
        pq.pop();
        if (pq.empty())
            return first;
        int sec = pq.top();
        pq.pop();
        if (first != sec)
            pq.push(first - sec);
    }
    return 0;

    return 0;
}