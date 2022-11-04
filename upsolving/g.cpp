#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<long long> dq;
    int n;
    cin >> n;
    while(n--){
        long long num;
        cin >> num;
        dq.push_back(num);
         
        while(!dq.empty() && dq.front() < num - 3000) dq.pop_front();
        
        cout << dq.size() << " ";
    }
    
}