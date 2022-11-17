// Problem E. 108995. Restore the string
#include <bits/stdc++.h>

using namespace std;

long long mod = 1e15 + 7;
long long x = 2;

long long getHash(string s){
    long long hash = 0;
    long long cur = 1;
    for (int i = 0; i < s.size(); i++){
        long long curHash = (s[i] - 'a') * cur % mod;
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

string getString(vector <long long> h){
    string res;
    long long cur = 1;
    res = ((h[0]) / cur + 97) % mod;
    for(int i = 0; i < h.size(); i++){
        if(i != 0) res += ((h[i] - h[i - 1]) / cur + 'a') % mod;

        cur = cur * x % mod;
    }
    return res;
}

int main(){
    long long n;
    cin >> n;
    vector<long long > v;
    for (int i = 0; i < n; i++){
        long long num;
        cin >> num;
        v.push_back(num); 
    }
    cout << getString(v);
}