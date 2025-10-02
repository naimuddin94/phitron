#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int q;
    cin >> q;

    int max_sum = 200000;
    
    bitset<200001> dp;

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        for (int s = max_sum - x; s >= 0; s--)
        {
            if (dp[s] == true)
            {
                dp[s + x] = true;
            }
        }
    }

    vector<int> cnt(max_sum + 1, 0);
    for (int i = 1; i <= max_sum; i++)
    {
        if (dp[i])
        {
            cnt[i] = cnt[i - 1] + 1;
        }
        else
        {
            cnt[i] = cnt[i - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        if (r > max_sum)
        {
            r = max_sum;
        }

        if (l > max_sum)
        {
            cout << 0 << endl;
            continue;
        }

        int result;
        if (l > 0)
        {
            result = cnt[r] - cnt[l - 1];
        }
        else
        {
            result = cnt[r];
        }

        cout << result << endl;
    }

    return 0;
}
