#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
int parent[105];
bool vis[105];
bool cycle = false;

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
            if(vis[ch] && parent[par] != ch){
                cycle = true;
            }
            if (!vis[ch])
            {
                bfs(ch);
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

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            bfs(i);
        }
    }
    
    if(cycle){
        cout << "Cycle detected" << endl;
    }else{
        cout << "No Cycle" << endl;
    }

    return 0;
}