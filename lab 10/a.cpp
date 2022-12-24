// Submit a solution for A-Marios War
#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[1005][1005];
int mush = 0;
queue<pair<int, int>> q;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n][m];

    int mush = 0;
    int time = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];

            if (arr[i][j] == 1) mush++;
            else if (arr[i][j] == 2) q.push(make_pair(i, j));
        }
    }

    // cout << mush << endl;
    // bfs(q.front().first, q.front().second);


    while(!q.empty()){
        if (!mush) break;

        int sz = q.size();
        for (int k = 0; k < sz; k++){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if ((i + 1) >= 0 && (i + 1) < n && j >= 0 && j < m){
                if (arr[i + 1][j] == 1){
                    arr[i + 1][j] = 2;
                    q.push(make_pair(i + 1, j));
                    mush--;
                }
            }
            if ((i - 1) >= 0 && (i - 1) < n && j >= 0 && j < m){
                if (arr[i - 1][j] == 1){
                    mush--;
                    arr[i - 1][j] = 2;
                    q.push(make_pair(i - 1, j));
                }
            }
            if (i >= 0 && i < n && (j + 1) >= 0 && (j + 1) < m){
                if (arr[i][j + 1] == 1){
                    arr[i][j + 1] = 2;
                    q.push(make_pair(i, j + 1));
                    mush--;
                }
            }
            if (i >= 0 && i < n && (j - 1) >= 0 && (j - 1) < m){
                if (arr[i][j - 1] == 1){
                    arr[i][j - 1] = 2;
                    q.push(make_pair(i, j - 1));
                    mush--;
                }
            }
        }
        // cout << mush << " " << time << endl;
        time++;
    }

    if (mush == 0) cout << time;
    else cout << -1;
}