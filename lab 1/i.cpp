// Problem I. 197984. Classroom of the Elite
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt_k = 0, cnt_s = 0;
    queue<int> q1;
    queue<int> q2;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'K') q1.push(i);
        else q2.push(i);
    }

    while(!q1.empty() && !q2.empty()){
        int kat = q1.front();
        q1.pop();
        int sak = q2.front();
        q2.pop();
        if (kat < sak){
            q1.push(kat + n);
        }
        else{
            q2.push(sak + n);
        }
    }
    
    if (!q1.empty()) cout << "KATSURAGI";
    else cout << "SAKAYANAGI";
}