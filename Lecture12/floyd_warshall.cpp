#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;
    int d[n][n];
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
    }

    for (int i = 0; i < n; i++){ //k
        for (int j = 0; j < n; j++){ //i
            for (int k = 0; k < n; k++){ //j
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}