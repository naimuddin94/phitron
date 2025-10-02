#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tar;
    cin >> tar;

    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (tar == arr[i])
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}