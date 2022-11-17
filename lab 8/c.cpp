// Problem C. 109920. Big (and not baby) tape
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

vector<int> rabinKarp(string s, string t){
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
    return res;
}

int main(){
    string s;
    cin >> s;

    int num;
    cin >> num;

    vector<pair<int, int>> v;
    for (int i = 0; i < s.size(); i++){
        v.push_back(make_pair(i, 0));
    }

    while(num--){
        string c;
        cin >> c;
        vector<int> h;
        h = rabinKarp(s, c);

        for (int i = 0; i < h.size(); i++){
            for (int j = 0; j < c.size(); j++){
                v[h[i] + j].second = 1;
            }
        }
        // for(int i = 0; i < h.size(); i++) cout << h[i] << " ";
    }
    
    for(int i = 0; i < v.size(); i++){
        if (v[i].second == 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}