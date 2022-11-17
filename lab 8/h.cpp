// Problem H. LCS
#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long X = 31;
vector<long long> p_pow(5001);

void getPowers(){
    p_pow[0] = 1;

    for(int i = 1 ; i < 5001; i++){
        p_pow[i] = p_pow[i - 1] * X % mod;
    }
}

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

bool rabinKarp(string s, long long smallHash, int l, int size) {
    vector<long long> hashes = getPrefixHashes(s);

    for (int i = 0; i < s.size() - size + 1; i++) {
        long long dif = hashes[i + size - 1];
        if (i != 0) dif -= hashes[i - 1];
        if (dif < 0) dif += mod;

        long long smallHashTemp = smallHash;

        if(i < l) dif = dif * p_pow[l - i] % mod;
        else{
            smallHashTemp = smallHashTemp * p_pow[i - l] % mod;
        }
        
        if(smallHashTemp == dif) return true;
    }
    return false;
}

int main(){
    int n; 
    cin >> n;

    getPowers();
    vector <string> v;
    for(int i = 0; i < n; i++){
        string s; 
        cin >> s;
        v.push_back(s);
    }
   
    vector <long long> firstHashes = getPrefixHashes(v[0]);
    string res = "";
    int mx = 0;

    for(int l = 0; l < v[0].size(); l++){
        int left = l;
        int right = v[0].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;

            long long hash = firstHashes[mid];

            if(l != 0) hash -= firstHashes[l - 1];
            if(hash < 0) hash += mod;

            bool ok = true;
            for(int j = 1; j < n; j++){ //other strings
                if(!rabinKarp(v[j], hash, l, mid - l + 1)){
                    ok = false;
                    break;
                }
            }

            if(ok){
                if(mid - l + 1 > mx){
                    mx = mid - l + 1;
                    res = v[0].substr(l, mid - l + 1);
                }
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    cout << res;
}