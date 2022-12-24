// Submit a solution for D-Try Again
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(5005);
vector<bool> used(5005);
vector<int> dist(5005);
vector<int> color(5005);
int n;

void bfs(int v){
    for (int i = 1; i <= n; i++) used[i] = false;

    queue<int> q;
    q.push(v);
    dist[v] = 0;
    used[v] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++){
            int vu = g[u][i];
            if (dist[vu] > dist[u] + 1){
                dist[vu] = dist[u] + 1;
                used[vu] = true;
                q.push(vu);
            }
        }
    }
}
int main(){
    int m, q;
    cin >> n >> m >> q;
    // g.resize(n);
    // dist.assign(5005, 1e9);
    // used.resize(n);
    // color.resize(n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        // a--;
        // b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        dist[i] = 1e9;
    }

    while(q--){
        int num, v;
        cin >> num >> v;
        // v--;
        if (num == 1){
            if (color[v] != 1){
                bfs(v);
                color[v] = 1;
            }
        }
        else{
            if (dist[v] == 1e9){
                cout << -1 << endl;
            }
            else{
                cout << dist[v] << endl;
            }
        }
    }
}