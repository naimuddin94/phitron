#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int r, c;

bool isValid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
    {
        return false;
    }
    return true;
}

void dfs(pair<int, int> src)
{
    vis[src.first][src.second] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = src.first + d[i].first;
        int cj = src.second + d[i].second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
        {
            dfs({ci, cj});
            vis[ci][cj] = true;
        }
    }
}

int main()
{

    cin >> r >> c;

    pair<int, int> from, to;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char ch;
            cin >> ch;
            grid[i][j] = ch;
            if (ch == 'A')
            {
                from = {i, j};
            }
            else if (ch == 'B')
            {
                to = {i, j};
            }
        }
    }

    memset(vis, false, sizeof(vis));
    dfs(from);

    if (vis[to.first][to.second])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}