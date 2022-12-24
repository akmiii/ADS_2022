// Submit a solution for I-Beta Tester
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> states;
vector<bool> used;
vector<int> ans;

bool detectCycle(int v){
    states[v] = 1;

    for (int i = 0; i < g[v].size(); i++){
        if (states[g[v][i]] == 1) return true;
        else if (states[g[v][i]] == 0){
            if (detectCycle(g[v][i])) return true;
        }
    }
    states[v] = 2;
    return false;
}

void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(!used[to]) dfs(to);
    }
    ans.push_back(v);
}


int main(){
    int n, m;
    cin >> n >> m;

    g.resize(n);
    used.resize(n);
    states.resize(n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    bool ok = false;
    for (int i = 0; i < n; i++){
        if (detectCycle(i)){
            ok = true;
            break;
        }
    }

    if (!ok){
        cout << "Possible" << endl;
        for (int i = 0; i < n; i++){
            if (!used[i]) dfs(i);
        }

        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] + 1 << " ";
        }
    }
    else cout << "Impossible";
}