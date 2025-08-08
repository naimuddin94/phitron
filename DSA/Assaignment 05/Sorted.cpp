#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        set<int> my_set;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            my_set.insert(val);
        }

        for (int it : my_set)
        {
            cout << it << " ";
        }
        
        cout << endl;
    }
    

    return 0;
}