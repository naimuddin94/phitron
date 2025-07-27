#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> my_queue;

    int q;
    cin >> q;

    while (q--)
    {
        int val;
        cin >> val;

        if (val == 0)
        {
            string name;
            cin >> name;
            my_queue.push(name);
        }
        else if (val == 1)
        {
            if (my_queue.empty())
            {
                cout << "Invalid" << endl;
            }
            else
            {
                cout << my_queue.front() << endl;
                my_queue.pop();
            }
        }
    }

    return 0;
}