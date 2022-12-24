// Submit a solution for H-Number of Island
#include<bits/stdc++.h>

using namespace std;

int n, m;
char arr[106][106];

void dfs(int i, int j){
    if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '1'){
        arr[i][j] = '0';
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] == '1'){
                dfs(i, j);
                cnt++;
            } 
        }
    }

    cout << cnt;
}