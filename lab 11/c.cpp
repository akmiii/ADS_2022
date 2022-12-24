// Submit a solution for C-111452. Travelling
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int> >> g;
vector<int> p;

int dsu_get(int v){
    if (v == p[v]) return v;
    return p[v] = dsu_get(p[v]);
}

void dsu_unite(int u, int v){
    u = dsu_get(u);
    v = dsu_get(v);

    if (u != v) p[u] = v;
}

int main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    int b = min(x, y);
    g.resize(n);
    p.resize(n);
    for (int i = 0; i < m; i++){
        string type;
        cin >> type;
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        if (type == "big"){
            g.push_back(make_pair(c*x, make_pair(u, v)));
        }
        if (type == "small"){
            g.push_back(make_pair(c*y, make_pair(u, v)));
        }
        if (type == "both"){
            g.push_back(make_pair(c*b, make_pair(u, v)));
        }
    }

    sort(g.begin(), g.end());
    // p.resize(n);
    int res = 0;

    for (int i = 0; i < n; i++){
        p[i] = i;
    }

    for (int i = 0; i < g.size(); i++){
        int u = g[i].second.first;
        int v = g[i].second.second;
        int w = g[i].first;
        if (dsu_get(u) != dsu_get(v)){
            res += w;
            dsu_unite(u, v);
        }
    }

    cout << res;
}