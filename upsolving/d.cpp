#include<bits/stdc++.h>

using namespace std;

bool isPrime(long long n){
    if (n == 0 || n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

bool contains(vector<long long> &v, int num){
    for(int i = 0; i < v.size(); i++){
        if (v[i] == num) return true;
    }
    return false;
}

int main(){
    long long num;
    cin >> num;

    int cnt = 0;
    vector<long long> v;
    // for(int i = 2; i <= num; i++){
    //     if (isPrime(i)) v.push_back(i);
    // }

    vector<long long> res;
    long long i = 2;
    bool ok = false;
    while(num != 1){
        if (num % i == 0){
            if (!ok){
                cnt++;
            }
            num /= i;
            ok = true;
        }
        else{
            i++;
            ok = false;                
        }
    }
    // cout << res.size();
    cout << cnt;

}