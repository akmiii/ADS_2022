// Problem B. Merge
#include <bits/stdc++.h>

using namespace std;

vector<int> res;
void merge(int * left, int * right, int n1, int n2){
    int l = 0, r = 0;
    while(l < n1 && r < n2){
        if (left[l] < right[r]){
            res.push_back(left[l]);
            l++;
        }
        else{
            res.push_back(right[r]);
            r++;
        }
    }
    while(l < n1){
        res.push_back(left[l]);
        l++;
    }
    while(r < n2){
        res.push_back(right[r]);
        r++;
    }

}
int main(){
    int n;
    cin >> n;
    int left[n];
    for(int i = 0; i < n; i++) cin >> left[i];

    int m;
    cin >> m;
    int right[m];
    for(int i = 0; i < m; i++) cin >> right[i];

    merge(left, right, n, m);

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}