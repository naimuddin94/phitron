#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;

    queue<string> line;

    while (q--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "ARRIVE")
        {
            string patient;
            cin >> patient;
            line.push(patient);
        }
        else if (cmd == "SERVE")
        {
            if (line.empty())
            {
                cout << "No patients" << endl;
            }
            else
            {
                line.pop();
            }
        }
        else if (cmd == "FIRST")
        {
            if (line.empty())
            {
                cout << "No patients" << endl;
            }
            else
            {
                cout << line.front() << endl;
            }
        }
        else if (cmd == "LAST")
        {
            if (line.empty())
            {
                cout << "No patients" << endl;
            }
            else
            {
                cout << line.back() << endl;
            }
        }
        else if (cmd == "COUNT")
        {
            cout << line.size() << endl;
        }
        else if (cmd == "SHOW")
        {
            if (line.empty())
            {
                cout << "No patients" << endl;
            }
            else
            {
                queue<string> tmp = line;
                while (!tmp.empty())
                {
                    cout << tmp.front() << " ";
                    tmp.pop();
                }
                cout << endl;
            }
        }
    }

    return 0;
}