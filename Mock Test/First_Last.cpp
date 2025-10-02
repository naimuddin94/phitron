#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<long long, pair<int, int>> mp;

    for (int i = 0; i < n; ++i)
    {
        long long val;
        cin >> val;

        if (mp.find(val) == mp.end())
        {
            mp[val] = {i + 1, i + 1};
        }
        else
        {

            mp[val].second = i + 1;
        }
    }

    for (auto &entry : mp)
    {
        cout << entry.first << " " << entry.second.first << " " << entry.second.second << endl;
    }

    return 0;
}