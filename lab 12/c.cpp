#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 2e3;

bool used[N];
bool arr[N][N];
int d[N];

struct Edge{
    int from;
    int to;
    int cost;

    Edge(int to, int cost){
        this->to = to;
        this->cost = cost;
    }
    Edge(int from, int to, int cost){
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};

vector<Edge> edges[N];

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(Edge(v, 1));
        edges[v].push_back(Edge(u, 1));
        // edges[i] = Edge(u, v, 1);

        arr[u][v] = 1;
        arr[v][u] = 1;
        // edges[u].push_back(Edge(v, 1));
        // edges[v].push_back(Edge(u, 1));
    }

    for (int i = 0; i <= n; i++) used[i] = false;
    for (int i = 1; i <= n; i++) d[i] = INF;

    used[1] = true;
    d[1] = 0;

    queue<int> q;
    while(!q.empty()){
        q.pop();
    }
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        used[u] = false;

        for (int i = 0; i < edges[u].size(); i++){
            int v = edges[u][i].to;
            int w = edges[u][i].cost;

            if(d[v] > d[u] + w){
                d[v] = d[u] + w;

                if(!used[v]){
                    used[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    int ans1 = d[n];
    for(int i = 1; i <= n; i++) edges[i].clear();

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(i == j) continue;
            if(!arr[i][j]){
                arr[i][j] = 1;
                edges[i].push_back(Edge(j, 1));
                edges[j].push_back(Edge(i, 1));
            }
        }
    }

    for (int i = 0; i <= n; i++) used[i] = false;
    for (int i = 1; i <= n; i++) d[i] = INF;

    used[1] = true;
    d[1] = 0;

    while(!q.empty()){
        q.pop();
    }
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        used[u] = false;

        for (int i = 0; i < edges[u].size(); i++){
            int v = edges[u][i].to;
            int w = edges[u][i].cost;

            if(d[v] > d[u] + w){
                d[v] = d[u] + w;

                if(!used[v]){
                    used[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    int ans2 = d[n];
    if(ans1 == INF || ans2 == INF){
        cout << -1;
    }
    else cout << max(ans1, ans2);


    
}