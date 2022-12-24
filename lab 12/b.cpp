// Submit a solution for C-195790. Nugman and Graph 3
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> g;
vector<int> dist, p;
vector<bool> used;

int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dist.assign(n, INF);
    p.resize(n, -1);
    used.resize(n);

    vector<int> path;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    int s, a, b, f;
    int res = 0;
    cin >> s >> a >> b >> f;
    s--;
    a--;
    b--;
    f--;
    dist[s] = 0;
    priority_queue<pair<int, int> > q;
    vector<int> res1, res2;
    q.push(make_pair(0, s));

    while(!q.empty()){
        int v = q.top().second, cur_d = -q.top().first;
        q.pop();
        if (cur_d > dist[v]) continue;

        for(int j = 0; j <  g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if (dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                p[to] = v;
                q.push({-dist[to], to});
            }
        }
    }

    res1.push_back(dist[a]);
    dist.assign(n, INF);
    used.assign(n, false);
    dist[a] = 0;

    q.push({0, a});
    while(!q.empty()){
        int v = q.top().second, cur_d = -q.top().first;
        q.pop();
        if (cur_d > dist[v]) continue;

        for(int j = 0; j <  g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if (dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                p[to] = v;
                q.push({-dist[to], to});
            }
        }
    }

    res1.push_back(dist[b]);
    dist.assign(n, INF);
    used.assign(n, false);
    dist[b] = 0;
    q.push({0, b});

    while(!q.empty()){
        int v = q.top().second, cur_d = -q.top().first;
        q.pop();
        if (cur_d > dist[v]) continue;

        for(int j = 0; j <  g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if (dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                p[to] = v;
                q.push({-dist[to], to});
            }


        }
    }

    res1.push_back(dist[f]);
    dist.assign(n, INF);
    used.assign(n, false);
    dist[s] = 0;
    q.push({0, s});

    while(!q.empty()){
        int v = q.top().second, cur_d = -q.top().first;
        q.pop();
        if (cur_d > dist[v]) continue;

        for(int j = 0; j <  g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if (dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                p[to] = v;
                q.push({-dist[to], to});
            }


        }
    }

    res2.push_back(dist[b]);
    dist.assign(n, INF);
    used.assign(n, false);
    dist[b] = 0;
    q.push({0, b});

    while(!q.empty()){
        int v = q.top().second, cur_d = -q.top().first;
        q.pop();
        if (cur_d > dist[v]) continue;

        for(int j = 0; j <  g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if (dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                p[to] = v;
                q.push({-dist[to], to});
            }


        }
    }

    res2.push_back(dist[a]);
    dist.assign(n, INF);
    used.assign(n, false);
    dist[a] = 0;

    q.push({0, a});

    while(!q.empty()){
        int v = q.top().second, cur_d = -q.top().first;
        q.pop();
        if (cur_d > dist[v]) continue;

        for(int j = 0; j <  g[v].size(); j++){
            int to = g[v][j].first, len = g[v][j].second;
            if (dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                p[to] = v;
                q.push({-dist[to], to});
            }


        }
    }

    res2.push_back(dist[f]);
    int sum1 = 0, sum2 = 0;


    for (int i = 0; i < res1.size(); i++){
        if (res1[i] != INF){
            sum1 += res1[i];
        }
        else{
            sum1 = -1;
            break;
        }
    }

    for (int i = 0; i < res2.size(); i++){
        if (res2[i] != INF){
            sum2 += res2[i];
        }
        else{
            sum2 = -1;
            break;
        }
    }

    if (sum1 == -1 && sum2 == -1){
        cout << -1;
    }
    else{
        cout << min(sum1, sum2);
    }    
}