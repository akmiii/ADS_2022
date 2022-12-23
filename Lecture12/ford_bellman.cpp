#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int from;
    int to;
    int cost;

    Edge(){

    }
    Edge(int from, int to, int cost){
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    vector<int> d(n, 1e9);

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(u, v, w);
    }

    int s;
    cin >> s;
    d[s] = 0;

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m; j++){
            d[edges[j].to] = min(d[edges[j].to], d[edges[j].from] + edges[j].cost);
        }
    }

    for (auto i : d) cout << i << " ";

}