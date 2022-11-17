// Problem B. Plagiarism
#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;
long long x = 31;

long long getHash(string s){
    long long hash = 0;
    long long cur = 1;
    for(int i = 0; i < s.size(); i++){
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
        if(i != 0){
            hashes[i] = (hashes[i] + hashes[i - 1]) % mod;
        }
        cur = (cur * x) % mod;
    }
    return hashes;
}

vector<int> rabinKarp(string s, string t){
    long long pat_hash = getHash(t); // for searching string
    vector<long long> hashes = getPrefixHashes(s); // in which string
    vector<int> res;

    for (int i = 0; i < s.size() - t.size() + 1; i++){
        long long dif = hashes[i + t.size() - 1];
        if (i != 0) dif -= hashes[i - 1];
        if (dif < 0) dif += mod;
        if (i != 0) pat_hash = (pat_hash * x) % mod;
        if (pat_hash == dif){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    string s1, s2;
    string pattern;
    cin >> s1 >> s2 >> pattern;

    vector<int> v1 = rabinKarp(s1, pattern);
    vector<int> v2 = rabinKarp(s2, pattern);

    // for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
    // for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
    
    int i1 = 0, i2 = 0;
    
    int cnt = 0;
    while(i1 < v1.size() && i2 < v2.size()){
        if (v1[i1] == v2[i2]){
            cnt++;  
            i1++;
            i2++;  
        }
        else if(v1[i1] < v2[i2]){
            i1++;
        }
        else{
            i2++;
        }
    }
    cout << cnt;
}