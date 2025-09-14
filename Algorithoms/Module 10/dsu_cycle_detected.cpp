#include <bits/stdc++.h>
using namespace std;

int leader[100];
int dsu_size[100];

int find_lead(int src)
{
    if (leader[src] == -1)
    {
        return src;
    }
    int l = find_lead(leader[src]);
    leader[src] = l;
    return l;
}

void dsu(int node1, int node2)
{
    int l1 = find_lead(node1);
    int l2 = find_lead(node2);

    if (dsu_size[l1] > dsu_size[l2])
    {
        leader[l2] = l1;
        dsu_size[l1] += dsu_size[l2];
    }
    else
    {
        leader[l1] = l2;
        dsu_size[l2] += dsu_size[l1];
    }
}

int main()
{
    memset(leader, -1, sizeof(leader));
    memset(dsu_size, 1, sizeof(dsu_size));

    bool cycle = false;

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int la = find_lead(a);
        int lb = find_lead(b);

        if (la == lb)
        {
            cycle = true;
        }
        else
        {
            dsu(a, b);
        }
    }

    if (cycle)
    {
        cout << "Cycle detected" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << leader[i] << endl;
    }
    return 0;
}