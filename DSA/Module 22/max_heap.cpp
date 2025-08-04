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

    int val;
    cin >> val;

    v.push_back(val);

    int curr = v.size() - 1;

    while (curr != 0)
    {
        int par = (curr - 1) / 2;
        if (v[curr] > v[par])
        {
            swap(v[curr], v[par]);
        }
        else
        {
            break;
        }
        curr = par;
    }

    for (int i : v)
    {
        cout << i << " ";
    }
    

    return 0;
}