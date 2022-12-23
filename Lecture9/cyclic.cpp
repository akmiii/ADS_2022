#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function (string s) {
	int n = s.size();
	vector<int> pi (n);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}
int main(){
    string s;
    cin >> s;
    vector <int> p = prefix_function(s);

    int ans = s.size() - p[s.size() - 1];

    //abcabcabc
    //000123456
    // 9 - 6 = 3




    // for(int i = 0; i < p.size();i++){
    //     cout << p[i] << " ";
    // }

    if(s.size() % ans == 0){
        cout << s.size() / ans;
    }
    else{
        cout << 1;
    }
}