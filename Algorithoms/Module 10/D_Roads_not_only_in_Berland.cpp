#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n=0) { init(n); }
    void init(int n) {
        p.resize(n+1);
        sz.assign(n+1, 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){ return p[x]==x ? x : p[x]=find(p[x]); }
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a==b) return false;
        if(sz[a] < sz[b]) swap(a,b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;

    DSU dsu(n);
    vector<pair<int,int>> bad;   // redundant edges (close cycles)

    for (int i = 0; i < n-1; ++i) {
        int a,b; cin >> a >> b;
        if (!dsu.unite(a,b)) bad.push_back({a,b});
    }

    // representatives of components in the forest (only non-redundant edges considered)
    vector<int> rep;
    for (int v = 1; v <= n; ++v)
        if (dsu.find(v) == v) rep.push_back(v);

    // Minimal ops = components - 1 = bad.size()
    cout << (int)bad.size() << "\n";
    for (int i = 0; i < (int)bad.size(); ++i) {
        // remove a redundant edge, connect two different components
        // connect rep[i] with rep[i+1] (chain)
        cout << bad[i].first << " " << bad[i].second << " "
             << rep[i] << " " << rep[i+1] << "\n";
    }
    return 0;
}
