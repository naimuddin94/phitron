#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> h(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> h[i];
        }

        int i1 = -1;
        int i2 = -1;

        for (int i = 0; i < n; ++i)
        {
            if (i1 == -1 || h[i] > h[i1])
            {
                i2 = i1;
                i1 = i;
            }
            else if (i2 == -1 || h[i] > h[i2])
            {
                i2 = i;
            }
        }

        if (i1 > i2)
        {
            swap(i1, i2);
        }

        cout << i1 << " " << i2 << endl;
    }
    return 0;
}
