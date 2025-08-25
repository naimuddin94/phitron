#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool pathvis[105];
bool vis[105];
bool cycle = false;

void dfs(int src){
    vis[src] = true;
    pathvis[src] = true;

    for (int child : adj_list[src])
    {
        if(vis[child] && pathvis[child]){
            cycle = true;
        }
        if(!vis[child]){
            dfs(child);
        }
    }
    pathvis[src] = false;
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
    }

    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));

    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            dfs(i);
        }
    }
    
    if(cycle){
        cout << "Cycle detected" << endl;
    }else{
        cout << "No Cycle" << endl;
    }

    return 0;
}