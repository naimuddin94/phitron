#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
       cin >> v[i];
    }

    long long countGroup = 0;
    long long prefixSum = 0;

    map<long long, int> freq;

    freq[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prefixSum += v[i];

        if(freq.find(prefixSum - k) != freq.end()){
            countGroup += freq[prefixSum - k]; 
        }

        freq[prefixSum]++;
    }

    cout << countGroup << endl;
    
    
    return 0;
}