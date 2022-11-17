// Problem D. Dominating Patterns
#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;
long long x = 31;

long long getHash(string s){
    long long hash = 0;
    long long cur = 1;
    for (int i = 0; i < s.size(); i++){
        long long curHash = (s[i] - 'a' + 1) * cur % mod;
        hash = (hash + curHash) % mod;
        cur = (cur * x) % mod;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s){
    vector<long long> hashes(s.size());

    long long cur = 1;
    for (int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * cur % mod;
        if (i != 0){
            hashes[i] = (hashes[i] + hashes[i - 1]) % mod;
        }
        cur = (cur * x) % mod;
    }
    return hashes;
}

int rabinKarp(string s, string t){
    long long pat_hash = getHash(t);
    vector<int> res;
    vector<long long> hashes = getPrefixHashes(s);

    for(int i = 0; i < s.size() - t.size() + 1; i++){
        long long dif = hashes[i + t.size() - 1];
        if (i != 0) dif -= hashes[i - 1];
        if (dif < 0) dif += mod;
        if (i != 0) pat_hash = (pat_hash * x) % mod;
        if (dif == pat_hash){
            res.push_back(i);
        }
    }
    return res.size();
}

int main(){
    int num;
    
    vector<pair<int, string>> res;
    while(cin >> num){
        vector<string> v;
        if (num == 0){
            break;
        }
        string pat;
        for (int i = 0; i < num; i++){
            cin >> pat;
            v.push_back(pat);
        }
        string text;
        cin >> text;

        int mx = 0;
        for (int i = 0; i < v.size(); i++){

            int rk = rabinKarp(text, v[i]); 
            res.push_back(make_pair(rk, v[i]));

            if (mx < rk){
                mx = rk;
            }
        }
        cout << mx << endl;
        for (int i = 0; i < res.size(); i++){
            if(res[i].first == mx) cout << res[i].second << endl;
        }
    }
}