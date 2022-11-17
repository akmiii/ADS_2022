// Problem A. 109670. Hash of digits
#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;
long long X = 11;

long long getHash(string s) {
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 47) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

int main(){
    int n;
    cin >> n;

    vector<string> v;
    map<string, bool> m;
    map<string, long long> mp;
    for (int i = 0; i < 2*n; i++){
        string x;
        cin >> x;
        v.push_back(x);
        mp[x] = getHash(x);
        m[x] = true;
    }

    map<string, long long> :: iterator it;

    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(cnt == n){
            break;
        }
        if(m[to_string(mp[v[i]])] == true){
            cout << "Hash of string " <<"\"" << v[i] <<"\"" << " is " << mp[v[i]] << endl;
            cnt++;
        }
    }
        
}