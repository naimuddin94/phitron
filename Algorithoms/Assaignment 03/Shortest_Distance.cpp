#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    long long adj_mat[n + 1][n + 1];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
            }
            else
            {
                adj_mat[i][j] = LLONG_MAX;
            }
        }
    }

    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX &&
                    adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int src, tar;
        cin >> src >> tar;

        if (adj_mat[src][tar] == LLONG_MAX)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << adj_mat[src][tar] << endl;
        }
    }

    return 0;
}
