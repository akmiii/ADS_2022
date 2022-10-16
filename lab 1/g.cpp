// Problem G. 149557. Vanya and Primes 2
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if (n == 0 or n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < 10000; i++){
        if (isPrime(i)) v.push_back(i); // 2 3 5 7 11 13 ..
    }
    vector<int> ind;
    for (int i = 0; i < v.size(); i++){
        if (isPrime(i+1)) ind.push_back(v[i]); // 3 5 11 ..
    }

    // for(int i  = 0; i < v.size(); i++){
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i <= ind.size(); i++){
        cout << ind[n-1];
        break;
    }
    
}