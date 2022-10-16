// Problem E. 153545. Boris vs Nursik
#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<int> boris;
    deque<int> nursik;
    int cnt = 0;
    for (int i = 0; i < 5; i++){
        int x;
        cin >> x;
        boris.push_back(x);
    }
    for (int i = 0; i < 5; i++){
        int x;
        cin >> x;
        nursik.push_back(x);
    }

    while(!boris.empty() && !nursik.empty() && cnt != 1000000){
        int b = boris.front();
        int n = nursik.front();
        boris.pop_front();
        nursik.pop_front();
        
        cnt++;

        if (b == 9 and n == 0){
            nursik.push_back(b);
            nursik.push_back(n);
        }
        else if (b == 0 and n == 9){
            boris.push_back(b);
            boris.push_back(n);
        }
        else if (b > n){
            boris.push_back(b);
            boris.push_back(n);
        }
        else {
            nursik.push_back(b);
            nursik.push_back(n);
        }
    }

    if (boris.empty()) cout << "Nursik" << " " << cnt;
    else if (nursik.empty()) cout << "Boris" << " " << cnt;
    else cout << "blin nichya";
}