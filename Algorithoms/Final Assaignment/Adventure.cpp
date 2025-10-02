#include <bits/stdc++.h>
using namespace std;

int wt[1005], val[1005];
int dp[1005][1005];

int knap(int i, int mx_wt)
{

    if (i < 0)
        return 0;

    if (dp[i][mx_wt] != -1)
        return dp[i][mx_wt];

    dp[i][mx_wt] = knap(i - 1, mx_wt);

    if (wt[i] <= mx_wt)
        dp[i][mx_wt] = max(dp[i][mx_wt], val[i] + knap(i - 1, mx_wt - wt[i]));

    return dp[i][mx_wt];
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, mx_wt;
        cin >> n >> mx_wt;

        for (int i = 0; i < n; ++i)
            cin >> wt[i];
        for (int i = 0; i < n; ++i)
            cin >> val[i];

        memset(dp, -1, sizeof(dp));
        cout << knap(n - 1, mx_wt) << endl;
    }
    return 0;
}
