#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int arr[t];
    queue<int> q;

    for (int i = 0; i <= t; i++){
        q.push(i);
        cout << i << " ";
    }

    cout << endl;

    for (int num = 1; num <= t; num++){
        // cout << num << " ";
        for(int j = 1; j <= num; j++){
            q.push(q.front());
            q.pop();
        }
        arr[q.front()] = num;
        q.pop();
        // num <- q.front();
    }

    for (int i = 0; i < t; i++) cout << arr[i] << " ";
}