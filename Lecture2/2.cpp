#include <bits/stdc++.h>

using namespace std;

// Eratosthenes sieve
bool isPrime[100];

void f(int n){
    for (int i = 2; i <= n; i++){
        isPrime[i] = true;
    }

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; i++){
        if (isPrime[i] == true){
            int j = i + i;
            while(j <= n){
                isPrime[j] = false;
                j += i;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if (isPrime[i]) cout << i << " ";
    }
} 

int main(){
    int n; 
    cin >> n;
    f(n);
}