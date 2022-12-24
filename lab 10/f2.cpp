// Submit a solution for F-John's graph
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(100000);
vector<bool> used;
vector<int> components;

void dfs(int v){
    used[v] = true;
    components.push_back(v);

    for (int i = 0; i < g[v].size(); i++){
        if (!used[g[v][i]]){
            dfs(g[v][i]);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    g.resize(n);
    used.resize(n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int s, f;
    cin >> s >> f;
    bool ok1 = false;
    bool ok2 = false;
    for(int i = 0; i < n; i++){
        if(!used[i]){
            components.clear();
            dfs(i);
            
            for(int i = 0; i < components.size();i++){
                if(components[i] == s) ok1 = true;
                if(components[i] == f) ok2 = true;

                if (ok1 && ok2){
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO"; 
}
