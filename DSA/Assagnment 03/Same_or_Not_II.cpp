#include <bits/stdc++.h>
using namespace std;

class My_stack
{
public:
    list<int> st;

    void push(int val)
    {
        this->st.push_back(val);
    }

    void pop()
    {
        this->st.pop_back();
    }

    int top()
    {
        return this->st.back();
    }

    bool empty()
    {
        return this->st.empty();
    }

    int size(){
        return this->st.size();
    }
};

class My_queue
{
public:
    list<int> st;

    void push(int val)
    {
        this->st.push_back(val);
    }

    void pop()
    {
        this->st.pop_front();
    }

    int front()
    {
        return this->st.front();
    }

    bool empty()
    {
        return this->st.empty();
    }

    int size(){
        return this->st.size();
    }
};

int main()
{
    int n, m;

    cin >> n >> m;

    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    My_stack st;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    My_queue q;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    bool is_same = true;

    while (!st.empty())
    {
        if (st.top() != q.front())
        {
            is_same = false;
            break;
        }
        st.pop();
        q.pop();
    }

    if (is_same)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}