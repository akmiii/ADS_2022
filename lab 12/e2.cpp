#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e5;
vector<long long> d, p;

int main(){
    int n;
    cin >> n;

    vector<vector<pair<int, long long>>> g(n + 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            long long w;
            cin >> w;
            if (w == INF) continue;
            g[i + 1].push_back({j + 1, w});
        }
    }

    // for(int i = 0; i < n; i++){
    //     for (int j = 0; j < g[i].size(); j++){
    //         cout << g[i][j].first << " " << g[i][j].second << endl;
    //     }
    // }

    d.assign(n + 1, 1e9);
    p.assign(n + 1, -1);

    for (int i = 1; i < n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 0; k < g[j].size(); k++){
                long long to = g[j][k].first, w = g[j][k].second;
                if (d[to] > d[j] + w){
                    d[to] = d[j] + w;
                    p[to] = j;
                }
            }
        }
    }
    bool flag = false;

    for (int i = 1; i <= n; i++){
        for (auto k : g[i]){
            long long to = k.first, w = k.second;
            if (d[to] > d[i] + w){
                flag = true;
                d[to] = d[i] + w;
                p[to] = i;
            }
            if (flag){
                cout << "YES" << endl;

                vector<int> path;
                vector<bool> used(n + 1, false);
                while(!used[i]){
                    used[i] = true;
                    i = p[i];
                }
                int u = i;
                path.push_back(u);
                u = p[u];
                while(u ^ i){
                    path.push_back(u);
                    u = p[u];
                }
                path.push_back(u);
                reverse(path.begin(), path.end());
                cout << path.size() << endl;
                for (auto a : path)
                    cout << a << " ";
                return 0;
            }
        }
    }
    if (!flag) cout << "NO" << endl;
}