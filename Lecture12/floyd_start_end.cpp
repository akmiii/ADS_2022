#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;
    int d[n][n];
    vector<vector<int>> p(n); // int p[n][n];

    for (int i = 0; i < n; i++){
        p[i].assign(n, -1);
    }

    int start, end;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        d[u][v] = w;
        p[u][v] = u;
    }

    for (int i = 0; i < n; i++){ //k
        for (int j = 0; j < n; j++){ //i
            for (int k = 0; k < n; k++){ //j
                if (d[j][k] > d[j][i] + d[i][k]){
                    d[j][k] = d[j][i] + d[i][k];
                    p[j][k] = i;
                }
            }
        }
    }

    cin >> start >> end;
    start--;
    end--;

    vector<int> path;

    for (int i = end; i != -1; i = p[start][i]){
        // cout << i + 1 << " ";
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++){
        cout << path[i] + 1 << " ";
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}