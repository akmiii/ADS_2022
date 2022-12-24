// Submit a solution for C-Aho-Corazick
#include <bits/stdc++.h>

using namespace std;

vector<unsigned long long> used;
vector<unsigned long long> parent;

// vector<unsigned long long> dist;

int main(){
    unsigned long long n, k;
    cin >> n >> k;

    parent.resize(1000000);
    used.resize(1000000);

    queue<unsigned long long> q;
    q.push(n);
    used[n] = true;

    if (n == k){
        cout << 0;
        return 0;
    }
    if(n > k){
        cout << n - k << endl;
        n -= 1;
        while(n != k){
            cout << n << " ";
            n--;
        }
        cout << k;
        return 0;
    }

    while(!q.empty()){
        unsigned long long v = q.front();
        q.pop();

        if (!used[2 * v] && v < k){
            
            q.push(2 * v);
            used[2 * v] = true;
            // dist[2 * v] = dist[v] + 1;
            parent[2 * v] = v;
            if (2 * v == k) break;
        }
        if (v - 1 > 0 && !used[v - 1]){
            
            q.push(v - 1);
            used[v - 1] = true;
            // dist[v - 1] = dist[v] + 1;
            parent[v - 1] = v;
            if (v - 1 == k) break;
        }
    
    }

    vector<unsigned long long> res;
    unsigned long long f = k, s = n;
    while(f != s){
        res.push_back(f);
        f = parent[f];
    }
    // return dist[f];
    // for(int i = 0; i < dist.size(); i++){
    //     cout << i << " " << dist[i] << " ";
    // }
    cout << res.size() << endl;
    
    for (int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
}

