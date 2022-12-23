#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100][100];
int color[100];

void dfs(int v){
    color[v] = 1;
    for (int i = 0; i < n; i++){
        if (arr[v][i] > 0 && color[i] == 0){
            dfs(i);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
        color[i] = 0;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (color[i] == 0){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}