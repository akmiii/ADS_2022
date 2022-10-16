// Problem F. 105787. Prime Numbers
#include <bits/stdc++.h>

using namespace std;

// Eratosthenes sieve
bool prime[1000000];

void f(vector<int>& p){
    for (int i = 2; i < 1000000; i++){
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

    for (int i = 2; i < 1000000; i++){ //по идее до sqrt()
        if (prime[i] == true){
            int j = i + i;
            while(j <= 100000){
                prime[j] = false;
                j += i;
            }
        }
    }

    for(int i = 2; i < 1000000; i++){
        if (prime[i]) p.push_back(i);
    }
} 

bool isPrime(int n){
    if (n == 1 || n == 0) return false;

    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true; 
}

int main(){
    int n;
    cin >> n;
    vector<int> primes1; // 1 method by Eratosthenes sieve (better)
    vector<int> primes2; // 2 method (my fav)
    f(primes1);
    cout << primes1[n-1] << endl;
    for (int i = 1; i < 1000000; i++){
        if (isPrime(i)) primes2.push_back(i);
    }
    cout << primes2[n-1];
}