// Problem G. Substrings
#include <bits/stdc++.h>

using namespace std;

long long mod = 1e15 + 7;
long long X = 31;

long long getHash(string s) {
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 'a' + 1) * curX % mod;
        hash = (hash + curHash) % mod;
        curX = (curX * X) % mod;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s) {
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % mod;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % mod;
        }
        curX = (curX * X) % mod;
    }
    return hashes;
}

long long rabinKarp(vector<long long> hashes, string t, string s) {
    long long smallHash = getHash(t);
    vector<int> res;
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0) hashDif -= hashes[i - 1];
        if (hashDif < 0) hashDif += mod;
        if (i != 0) smallHash = (smallHash * X) % mod;
        if (smallHash == hashDif) {
            res.push_back(i);
        }
    }
    return res.size();
}

int main() {
    string s, t;
    cin >> s;
    long long n;
    cin >> n;
    vector<long long> hashes = getPrefixHashes(s);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        t = s.substr(l-1, r - l + 1);
        cout << rabinKarp(hashes, t, s) << endl;
        // cout << t << endl;
    }


}