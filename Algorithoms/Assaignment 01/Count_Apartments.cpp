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

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
        {
            dfs(ci, cj);
            vis[ci][cj] = true;
        }
    }
}

int main()
{

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char ch;
            cin >> ch;
            grid[i][j] = ch;
        }
    }

    memset(vis, false, sizeof(vis));
    int cnt = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}