#include <bits/stdc++.h>
using namespace std;

int arr[100];

bool subset_sum(int i, int sum)
{
    if (i < 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }

    if (arr[i] <= sum)
    {
        bool opt1 = subset_sum(i-1, sum - arr[i]);
        bool opt2 = subset_sum(i-1, sum);
        return opt1 || opt2;
    }
    else
    {
        bool opt2 = subset_sum(i-1, sum);
        return opt2;
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum;
    cin >> sum;

    if (subset_sum(n - 1, sum))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}