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

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int rooms = 1;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            rooms += dfs(ci, cj);
        }
    }
    return rooms;
}

int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    vector<int> apartments;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                int rooms = dfs(i, j);
                apartments.push_back(rooms);
            }
        }
    }

    if (apartments.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        sort(apartments.begin(), apartments.end());
        for (int it : apartments)
        {
            cout << it << " ";
        }
    }

    return 0;
}
