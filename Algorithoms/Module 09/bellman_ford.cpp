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

int n, e;
int dis[100];
vector<Edge> edge_list;

void bellman_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b])
            {
                dis[ed.b] = dis[ed.a] + ed.c;
            }
        }
    }

    bool cycle = false;

    for (auto ed : edge_list)
    {
        if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative cycle detected" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> " << dis[i] << endl;
        }
        }
}

int main()
{
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;

    bellman_ford();

    return 0;
}