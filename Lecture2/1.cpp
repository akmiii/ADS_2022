#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    if (x == 1) return false;

    for (int i = 2; i <= sqrt(x); i++){
        if (x % i == 0) return  false;
    }
    return true;
}

int main(){
    int num;
    cin >> num;
    if (isPrime(num)) cout << "Yes";
    else cout << "No";
}