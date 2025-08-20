#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[500];
bool vis[500];

int bfc_sum(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    int sum = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        sum += par;

        for (int ch : adj_list[par])
        {
            if (!vis[ch])
            {
                q.push(ch);
                vis[ch] = true;
            }
        }
    }

    return sum;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int ans = bfc_sum(0);

    cout << ans << endl;

    return 0;
}