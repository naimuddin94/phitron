#include <bits/stdc++.h>
using namespace std;

int lead[100005];
int group_size[100005];
int cmp;
int mx = 1;

int find_lead(int node)
{
    if (lead[node] == -1)
    {
        return node;
    }
    int fined_leader = find_lead(lead[node]);
    lead[node] = fined_leader;
    return fined_leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find_lead(node1);
    int leader2 = find_lead(node2);

    if (leader1 == leader2)
    {
        return;
    }

    if (group_size[leader1] > group_size[leader2])
    {
        lead[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx, group_size[leader1]);
    }
    else
    {
        lead[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx, group_size[leader2]);
    }

    cmp--;
}

int main()
{
    int n, e;
    cin >> n >> e;

    cmp = n;

    for (int i = 0; i < n; i++)
    {
        lead[i] = -1;
        group_size[i] = 1;
    }

    

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        dsu_union(a, b);

        cout << cmp << " " << mx << endl;
    }

    return 0;
}