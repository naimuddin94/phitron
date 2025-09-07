#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e;
vector<Edge> edge_list;
long long dis[1005];
bool cycle = false;

void bellman_ford()
{
    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            if (dis[ed.a] != LLONG_MAX && dis[ed.a] + ed.c < dis[ed.b])
            {
                dis[ed.b] = dis[ed.a] + ed.c;
            }
        }
    }

    // Check for negative cycle
    for (auto ed : edge_list)
    {
        if (dis[ed.a] != LLONG_MAX && dis[ed.a] + ed.c < dis[ed.b])
        {
            cycle = true;
            break;
        }
    }
}

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }

    int src, t;
    cin >> src >> t;

    dis[src] = 0;

    bellman_ford();

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        while (t--)
        {
            int tar;
            cin >> tar;

            if (dis[tar] == LLONG_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[tar] << endl;
            }
        }
    }

    return 0;
}
