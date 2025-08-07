#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());
    
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    cout << (v[0]-1) * (v[1]-1) << endl;

    return 0;
}