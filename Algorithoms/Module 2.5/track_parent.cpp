#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis[100];
int parent[100];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int ch : adj_list[par])
        {
            if (!vis[ch])
            {
                q.push(ch);
                vis[ch] = true;
                parent[ch] = par;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    int node = dst;

    while (node != -1)
    {
        cout << node << " ";
        node = parent[node];
    }
    

    return 0;
}