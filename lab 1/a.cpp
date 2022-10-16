// Problem A. 111521. Royal Flush
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> v;

    for(int i = 0; i < t; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i = 0; i < v.size(); i++){
        deque <int> d;
        stack <int> st;
        for(int j = 1; j < v[i]; j++){
            st.push(j);
        }

        d.push_back(v[i]);
        while(!st.empty()){
            d.push_front(st.top()); // 3
            int prev = st.top(); //3
            st.pop(); //st: 2 1
            for(int i = 0; i < prev; i++){
                int a = d.back(); // 4 3
                d.push_front(a); //4 3 4      3 4 3
                d.pop_back();  // 4 3         3 4
            }

        }
        while(!d.empty()){
            cout << d.front() << " ";
            d.pop_front();
        }
    cout << endl;
    }
    
    // if(t - v.size() > 0){
    //     for(int i = 0; i < t - v.size(); i++){
    //         deque <int> d;
    //         stack <int> st;
    //         for(int i = 1; i < v[v.size() - 1]; i++){
    //             st.push(i);
    //         }
    //         d.push_back(v[v.size() - 1]);
    //         while(!st.empty()){
    //             d.push_front(st.top());
    //             int prev = st.top();
    //             st.pop();
    //             for(int i = 0; i < prev; i++){
    //                 int a = d.back();
    //                 d.push_front(a);
    //                 d.pop_back();
    //             }
    //         } 
    //         while(!d.empty()){
    //             cout << d.front() << " ";
    //             d.pop_front();
    //         }
    //         cout << endl;
    //     }
    // }
}