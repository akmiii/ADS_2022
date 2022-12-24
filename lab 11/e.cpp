// Submit a solution for E-196802. Nugman and Graph 2
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> p;

int dsu_get(int v) {
	if (v == p[v]) return v;
	return p[v] = dsu_get(p[v]);
}

bool dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);

	if (a != b){
		p[a] = b;
        return true;
    }
    return false;
    
}

int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    p.resize(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; i++) p[i] = i;

    vector<int> res;
    int cnt = 0;

    for (int i = n - 1; i >= 0; i--){
        res.push_back(cnt);
        cnt += 1;
        for (int j = 0; j < g[i].size(); j++){
            if (i < g[i][j] && dsu_unite(i, g[i][j])) 
                cnt -= 1;
        }
        // cout << cnt << endl;
        
    }

    for (int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << endl;
    }
    
}