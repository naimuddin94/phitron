#include <bits/stdc++.h>
using namespace std;

int arr[100];
int dp[1000][1000];

bool subset_sum(int i, int sum)
{
    if (i < 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }

    if (arr[i] <= sum)
    {
        bool opt1 = subset_sum(i - 1, sum - arr[i]);
        bool opt2 = subset_sum(i - 1, sum);
        dp[i][sum] = opt1 || opt2;
        return dp[i][sum];
    }
    else
    {
        dp[i][sum] = subset_sum(i - 1, sum);
        return dp[i][sum];
    }
}

int main()
{
    int n;
    cin >> n;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum % 2 == 1)
    {
        cout << "NO\n";
    }
    else
    {

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         dp[i][j] = -1;
        //     }
        // }

        if (subset_sum(n - 1, sum / 2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}