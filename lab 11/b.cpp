// Submit a solution for B-110809. Duck Islands
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> g(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> g[i];
        // sum += g[i];
    }
    sort(g.begin(), g.end());
    int mn = g[0];
    for (int i = 1; i < n; i++){
        sum += g[i] + mn;
    }

    cout << sum;
}