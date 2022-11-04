// Problem C. Nugman and Stack
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* prev;
    Node(int val){
        this -> val = val;
        prev = nullptr;
    }
};

class Stack{
public:
    Node* top;
    int sz;

    Stack(){
        top = nullptr;
        sz = 0;
    }

    int push(int val){
        Node* newNode = new Node(val);
        if (!top) top = newNode;
        else{
            newNode -> prev = top;
            top = newNode;
        }
        
        Node* cur = top;
        int ans = -1;
        cur = top -> prev;

        int mn = val;
        while(cur){
            if (cur -> val <= val){
                mn = cur -> val;
                ans = mn;
                break;
            }
            cur = cur -> prev;
        }
    
        return ans;
    }

};

int main(){
    int n;
    cin >> n;

    Stack st;
    while(n--){
        int x;
        cin >> x;
        cout << st.push(x) << " ";
    }
}