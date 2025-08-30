#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1001][1001];
bool vis[1001][1001];
pair<int, int> mv[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool isValid(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m)
    {
        return false;
    }
    return true;
    // return r > 0 && c > 0 && r <= n && c <= m;
}

void dfs(int r, int c)
{
    vis[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        
        int cr = r + mv[i].first;
        int cc = c + mv[i].second;

        if (isValid(cr, cc) && !vis[cr][cc] && grid[cr][cc] == '.')
        {
            dfs(cr, cc);
        }
    }
}

int main()
{

    cin >> n >> m;

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> grid[i][j];
        }
    }

    int si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;

    dfs(si, sj);

    if (vis[ti][tj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}