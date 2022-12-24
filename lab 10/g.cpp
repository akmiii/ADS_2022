// Submit a solution for G-Fly Me to the Moon
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(505);
vector<int> color(505);
stack<int> st;
vector<int> cycle;

bool dfss(int v, int a, int b){
    color[v] = 1;
    for (int i = 0; i < g[v].size(); i++){
        int vu = g[v][i];
        if (v == a && b == vu) continue;
        if (!color[vu]){
            if (dfss(vu, a, b)) return true;
        }
        else if (color[vu] == 1) return true;
    }

    color[v] = 2;
    return false;
}

bool dfs(int v){
    color[v] = 1;
    st.push(v);

    for (int i = 0; i < g[v].size(); i++){
        int vu = g[v][i];
        if (!color[vu]){
            if (dfs(vu)) return true;
        }
        else if (color[vu] == 1){
            while(st.top() != vu){
                cycle.push_back(st.top());
                st.pop();
            }
            cycle.push_back(vu);
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    color[v] = 2;
    if (!st.empty()) st.pop();
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    bool isCycle = false;
    for (int i = 1; i <= n; i++){
        if (!color[i]){
            isCycle = dfs(i);
            if (isCycle) break;
        }
    }

    if (!isCycle){
        cout << "YES";
        return 0;
    }

    for (int i = 0; i < cycle.size() - 1; i++){
        int a = cycle[i];
        int b = cycle[i + 1];

        for (int j = 1; j <= n; j++){
            color[j] = 0;
        }
        isCycle = false;
        for (int j = 1; j <= n; j++){
            if (!color[j]){
                isCycle |= dfss(j, a, b);
            }
        }
        if (!isCycle){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}