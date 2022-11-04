#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if (n == 0 || n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if (isPrime(i)) v.push_back(i);
    }
    for(int i = 0; i < v.size() - 1; i++){
        for(int j = i; j < v.size(); j++){
            if (v[i] + v[j] == n){
                cout << v[i] << " " << v[j];
                return 0;
            }
        }
    }
}