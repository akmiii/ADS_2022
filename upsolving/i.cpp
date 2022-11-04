#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> v;
    
    while(n--){
        long long val;
        cin >> val;

        v.push_back(val);
    }

    for(int i = 0; i < v.size(); i++){
        long long num = v[i];
        stack<long long> st;
        while(num != 0){
            if (num % 2 == 1){
                if (!st.empty() && st.top() == 0) st.pop();
                else st.push(1);
            }
            if (num % 2 == 0){
                st.push(0);
            }

            num/=2;
        }
        if(st.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}