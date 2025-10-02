#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (s1.size() != s2.size())
        {
            cout << "NO" << endl;
            continue;
        }

        int free[26] = {0};

        for (char c : s1)
        {
            free[c - 'a']++;
        }

        int anagram = true;

        for (char c : s2)
        {
            free[c - 'a']--;
            if (free[c - 'a'] < 0)
            {
                anagram = false;
                break;
            }
        }

        if (anagram)
        {

            for (int it : free)
            {
                if (it != 0)
                {
                    anagram = false;
                    break;
                }
            }
        }

        if (anagram)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}