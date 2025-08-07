#include <bits/stdc++.h>
using namespace std;

void insert_head(vector<int> &v, int val)
{
    v.push_back(val);

    int curr = v.size() - 1;

    while (curr != 0)
    {
        int par = (curr - 1) / 2;
        if (v[curr] > v[par])
        {
            swap(v[curr], v[par]);
        }
        else
        {
            break;
        }
        curr = par;
    }
}

void delete_head(vector<int> &v)
{
    if (v.empty())
        return;

    v[0] = v.back();
    v.pop_back();

    int curr = 0;
    int n = v.size();

    while (true)
    {
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;
        int largest = curr;

        if (left < n && v[left] > v[largest])
        {
            largest = left;
        }
        if (right < n && v[right] > v[largest])
        {
            largest = right;
        }

        if (largest == curr)
            break;

        swap(v[curr], v[largest]);
        curr = largest;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert_head(v, val);
    }

    delete_head(v);

    for (int it : v)
    {
        cout << it << " ";
    }

    return 0;
}
