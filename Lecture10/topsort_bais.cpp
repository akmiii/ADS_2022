#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100][100];
int color[100];
bool over;

void dfs(int v, int f){
    if (v == f){
        over = true;
        cout << f << " ";
        return;
    }
    if (!over){
        cout << v << " ";
        color[v] = 1;
        for (int i = 0; i < n; i++){
            if (arr[v][i] > 0 && color[i] == 0){
                dfs(i, f);
            }
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

    over = false;
    dfs(0, 8);
}