#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student l, Student r)
    {
        return l.marks == r.marks ? l.roll > r.roll : l.marks < r.marks;
    }
};

int main()
{
    priority_queue<Student, vector<Student>, cmp> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;

        Student obj(name, roll, marks);
        pq.push(obj);
    }

    int t;
    cin >> t;

    while (t--)
    {
        int c;
        cin >> c;

        if (c == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;

            Student obj(name, roll, marks);
            pq.push(obj);

            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        }
        else if (c == 1)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            }
        }
        else if (c == 2)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                pq.pop();
                if (pq.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
                }
            }
        }
    }

    return 0;
}