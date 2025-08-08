#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int id;

    Person(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
};

bool cmp(Person l, Person r)
{
    return l.name == r.name ? l.id > r.id : l.name < r.name;
}

int main()
{
    int t;
    cin >> t;

    vector<Person> v;

    for (int i = 0; i < t; i++)
    {
        string name;
        int id;
        cin >> name >> id;
        Person obj(name, id);
        v.push_back(obj);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < t; i++)
    {
        cout << v[i].name << " " << v[i].id << endl;
    }

    return 0;
}
