// Submit a solution for B-Path
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[105][105];
vector<bool> used;
int cnt = 0;

int bfs(int s, int f){
    
    queue<pair<int, int>> q;
    q.push(make_pair(s, cnt));
    used[s] = true;

    while(!q.empty() && q.front().first != f){
        int temp = q.front().first;
        int dist = q.front().second;
        used[temp] = true;
        q.pop();

        for (int i = 0; i < n; i++){
            if (!used[i] && arr[temp][i]){
                q.push(make_pair(i, dist + 1));
                // cnt++;
            } 
        }  
    }
    
    if (!q.empty()) return q.front().second;
    return -1;
}

int main(){
    cin >> n;

    used.resize(n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int a, b;
    cin >> a >> b;
    a--; 
    b--;
    cout << bfs(a, b);
}