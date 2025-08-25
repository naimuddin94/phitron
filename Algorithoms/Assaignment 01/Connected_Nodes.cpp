#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int idx;
        cin >> idx;
        if (adj_list[idx].size() > 0)
        {
            sort(adj_list[idx].begin(), adj_list[idx].end(), greater<int>());

            for (int it : adj_list[idx])
            {
                cout << it << " ";
            }
            
        }
        else
        {
            cout << "-1";
        }

        cout << endl;
    }

    return 0;
}