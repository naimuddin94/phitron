#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;

    bool isLucky = false;

    for (char c : n)
    {
        if (c == '7')
        {
            isLucky = true;
            break;
        }
    }

    if (isLucky)
        cout << "Lucky" << endl;
    else
        cout << "Not Lucky" << endl;

    return 0;
}