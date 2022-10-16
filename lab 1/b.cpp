// Problem B. 187147. Nugman and Stack
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    cin >> n;
    int x;
    vector<int> v;
    stack<int> st;
    for (int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
        st.push(x);
    }
    vector<int> ans;
    int temp = 1;
    reverse(v.begin(), v.end());
    while(!st.empty()){
        int a = st.top();
        st.pop();
        
        for (int i = temp; i < v.size(); i++){
            
            if (a >= v[i]){
                // cout << v[i] << " " << i << endl;
                ans.push_back(v[i]);
                break;
            }
            if (i == v.size() - 1){
                // cout << -1 << endl;
                ans.push_back(-1);
            }
        }
        temp++;
    }
    // for (int i = 0; i < v.size(); i++){
    //     for (int j = i + 1; j < v.size(); j++){
    //         if (v[j] <= v[i]){
    //             ans.push_back(v[j]);
    //             break;
    //         }
    //         if (j == v.size() - 1){
    //             ans.push_back(-1);
    //         }
    //     }
    // }
    ans.push_back(-1);

    for (int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }

}