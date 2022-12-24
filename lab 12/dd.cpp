#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<vector<pair<int, long long>>> g;
int n;

bool bfs(long long cost){
    queue<int> q;
    vector<bool> used(n);
    q.push(0);
    used[0] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        if (v == n - 1) return true;
        for (int i = 0; i < g[v].size(); i++){
            int to = g[v][i].first;
            long long w = g[v][i].second;
            if (!used[to] && cost >= w){
                used[to] = true;
                q.push(to);
            }
        }
    }
    return false;
}

long long binSearch(long long l, long long r){
    long long res = -1;
    while(l <= r){
        long long mid = l + (r - l)/2;
        if (bfs(mid)){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    return res;
}

int main(){
    cin >> n;
    g.resize(n);

    vector<pair<long long, long long>> coordinates;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        coordinates.push_back({x, y});
    }

    if (n == 1){
        cout << 0;
        return 0;
    }

    for (int i = 0; i < coordinates.size(); i++){
        for (int j = i + 1; j <  coordinates.size(); j++){
            g[i].push_back({j, abs(coordinates[i].first - coordinates[j].first) + abs(coordinates[i].second - coordinates[j].second)});
            g[j].push_back({i, abs(coordinates[i].first - coordinates[j].first) + abs(coordinates[i].second - coordinates[j].second)});

        }
    }

    cout << binSearch(1, 2 * 1e9);
}