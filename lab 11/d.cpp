// Submit a solution for D-111453. Minimal cost
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> min_e, sel_e;

const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    int arr[n][n];

    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    used.resize(n);
    min_e.assign(n, INF);
    sel_e.assign(n, -1);

    min_e[0] = 0;
    
    for (int i = 0; i < n; i++){
        int v = -1;
        for (int j = 0; j < n; j++){
            if (!used[j] && (v == -1 || min_e[j] < min_e[v])){
                v = j;
            }
        }
        // if (min_e[v] == 1e9){
        //     cout << "NO";
        //     return 0;
        // }
        used[v] = true;
        if (sel_e[v] != -1){
            res += arr[v][sel_e[v]];
        }
        for (int j = 0; j < n; j++){
            if (arr[v][j] < min_e[j]){
                min_e[j] = arr[v][j];
                sel_e[j] = v;
            }
        }
    }

    cout << res;
}