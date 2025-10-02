#include <bits/stdc++.h>
using namespace std;

int dp[35];

int tetra(int n)
{
    if (n < 2)
        return n;

    if (n == 2)
        return 1;

    if (n == 3)
        return 2;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = tetra(n - 1) + tetra(n - 2) + tetra(n - 3) + tetra(n - 4);

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    cout << tetra(n) << endl;

    return 0;
}