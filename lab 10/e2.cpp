// Submit a solution for E-KH2O - potassium hydroxide???
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int arr[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;
        if (arr[x][y] == 0 or arr[x][z] == 0 or arr[y][z] == 0){
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }

}