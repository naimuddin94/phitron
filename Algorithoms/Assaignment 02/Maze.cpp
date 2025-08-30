#include <bits/stdc++.h>
using namespace std;

int n, m;
int si, sj, ti, tj;

char grid[1005][1005];
bool vis[1005][1005];

pair<int, int> parent[1005][1005];

pair<int, int> mv[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m)
    {
        return false;
    }
    return true;
}

bool bfs()
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + mv[i].first;
            int cj = par.second + mv[i].second;

            if (isValid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                vis[ci][cj] = true;
                parent[ci][cj] = par;

                if (ci == ti && cj == tj)
                    return true;

                q.push({ci, cj});
            }
        }
    }
    return false;
}

void markPath()
{
    int x = ti, y = tj;
    while (!(x == si && y == sj))
    {
        if (grid[x][y] == '.')
            grid[x][y] = 'X';
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char val;
            cin >> val;
            grid[i][j] = val;
            if (val == 'R')
            {

                si = i;
                sj = j;
            }
            if (val == 'D')
            {
                ti = i;
                tj = j;
            }
        }
    }

    if (bfs())
    {
        markPath();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}