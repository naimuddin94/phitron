#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;


    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        pq.push(val);
    }
    
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    
    
    return 0;
}