#include <bits/stdc++.h>
using namespace std;

bool is_valid(string &s)
{
    stack<char> st;

    for (char c : s)
    {
        if (!st.empty() && ((st.top()=='0' && c=='1') || (st.top()=='1' && c=='0')))
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }

    return st.empty();
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        if (is_valid(s))
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