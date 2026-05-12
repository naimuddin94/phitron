#include <bits/stdc++.h>
using namespace std;

int val[1005];
int weight[1005];
int dp[1005][1005];

int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;

    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];

    // If we can take this item
    if (weight[i] <= mx_weight)
    {
        // Option 1: take this item (unbounded, so i stays same)
        int op1 = knapsack(i, mx_weight - weight[i]) + val[i];
        // Option 2: skip this item
        int op2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(op1, op2);
    }
    else
    {
        dp[i][mx_weight] = knapsack(i - 1, mx_weight);
    }

    return dp[i][mx_weight];
}

int main()
{
    int n, W;
    cin >> n; // number of items

    for (int i = 0; i < n; i++)
        cin >> val[i]; // values

    for (int i = 0; i < n; i++)
        cin >> weight[i]; // weights

    cin >> W; // max capacity

    memset(dp, -1, sizeof(dp));

    cout << knapsack(n - 1, W) << endl;

    return 0;
}
