#include <bits/stdc++.h>
using namespace std;

int leader[100005];
int dsu_size[100005];

int find_lead(int src)
{
    if (leader[src] == -1)
    {
        return src;
    }
    int led = find_lead(leader[src]);
    leader[src] = led;
    return led;
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

    int n, e;
    cin >> n >> e;

    int cycle_cnt = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int la = find_lead(a);
        int lb = find_lead(b);

        if (la == lb)
        {
            cycle_cnt++;
        }
        else
        {
            dsu(a, b);
        }

    }

    cout << cycle_cnt << endl;

    return 0;
}