// From one vertex to another vertex
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> g;
vector<int> dist, p;
vector<bool> used;

int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dist.assign(n, INF);
    p.resize(n, -1);
    used.resize(n);

    vector<int> path;

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        // u--;
        // v--;
        g[u].push_back(make_pair(v, w));
    }

    int s, f;
    cin >> s >> f;
    // s--;
    dist[s] = 0;

    for (int i = 0; i < n; i++){
        int v = -1;
        for (int j = 0; j < n; j++){
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }
        // if (dist[v] == INF) break;

        used[v] = true;

        for (int j = 0; j < g[v].size(); j++){
            int to = g[v][j].first;
            int len = g[v][j].second;

            if (dist[v] + len < dist[to]){
                dist[to] = dist[v]+ len;
                p[to] = v;
            }
        }
    }

    // for (int i : p) cout << i  << " ";
    // cout << endl;
    // for (int i : dist) cout << i << " ";
	path.push_back(f);
	for (int i = f; i != s; i = p[i]) {
		path.push_back(p[i]);
	}

	reverse(path.begin(), path.end());
	for (auto i : path) cout << i << " ";

}