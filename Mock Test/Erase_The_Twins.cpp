#include <bits/stdc++.h>
using namespace std;

int getLength(string &s)
{
    stack<char> stk;

    for (char ch : s)
    {
        if (!stk.empty() && stk.top() == ch)
        {
            stk.pop();
        }
        else
        {
            stk.push(ch);
        }
    }

    return stk.size();
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << getLength(s) << endl;
    }

    return 0;
}