#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];
bool vis[100];
int level[100] = {-1};

void bfc(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

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
                level[ch] = level[par] + 1;
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

    int src, dest;
    cin >> src >> dest;

    bfc(src);

    cout << level[dest] << endl;

    return 0;
}