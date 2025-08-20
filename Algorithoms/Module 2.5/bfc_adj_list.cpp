#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[500];
bool vis[500] = {false};

void bfc(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        cout << f << " ";

        for (int it : adj_list[f])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = true;
            }
        }
    }
}

int main()
{
    int a, e;
    cin >> a >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfc(0);

    return 0;
}