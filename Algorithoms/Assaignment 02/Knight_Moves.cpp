#include <bits/stdc++.h>
using namespace std;

class CustomStuck
{
public:
    int row;
    int col;
    int steps;
    CustomStuck(int row, int col, int steps)
    {
        this->row = row;
        this->col = col;
        this->steps = steps;
    }
};

int n, m;
int si, sj, ti, tj;

int min_move, cnt;

pair<int, int> mv[8] = {
    {-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};

bool isValid(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m)
    {
        return false;
    }
    return true;
}

int bfs()
{
    bool vis[105][105];
    memset(vis, false, sizeof(vis));
    queue<CustomStuck> q;

    q.push(CustomStuck(si, sj, 0));

    while (!q.empty())
    {
        CustomStuck par = q.front();
        q.pop();

        if (par.row == ti && par.col == tj)
        {
            return par.steps;
        }

        for (int i = 0; i < 8; i++)
        {
            int ci = par.row + mv[i].first;
            int cj = par.col + mv[i].second;

            if (isValid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push(CustomStuck(ci, cj, par.steps + 1));
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        cin >> si >> sj >> ti >> tj;

        cout << bfs() << endl;
    }

    return 0;
}
