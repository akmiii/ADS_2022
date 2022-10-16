// Problem A. 187089. Nearest number
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int val){
        this -> val = val;
        next = nullptr;
    }
};

class LinkedList{
    // Node* head;
    // Node* tail;
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        
        if (!head){
            head = newNode;
            tail = head;
        }
        tail -> next = newNode;
        tail = tail -> next;
        // Node* cur = head;
        // while(cur != nullptr){
        //  if (cur -> next == nullptr){
        //      cur -> next = newNode;
        //      break;
        //  }
        //  cur = cur -> next;
        // }
        
    }
    

    // void change(int k){
    //     Node* cur = head;
        
    //     while(cur != nullptr){
    //         cur -> val = abs(k - cur -> val);
    //         cur = cur -> next;
    //     }
    // }

    // int findOffset(){
    //     Node* cur = head;

    //     long long mn = 10000000;
    //     long long ind = 0;
    //     long long res = 0;
    //     while(cur != nullptr){
    //         if (mn > cur -> val){
    //             mn = cur -> val;
    //             res = ind;
    //         }
    //         ind++;
    //         cur = cur -> next;
    //     }
    //     return res;
    // }


    void print(){
        Node* cur = head;
        while(cur != nullptr){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};

int main(){
    LinkedList list;
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        list.push_back(num);
    }
    int k;
    cin >> k;
    // list.print();
    int ind = 1, dif = abs(k - list.head -> val), res = 0;
    // cout << "\n" << dif;
    Node* cur = list.head -> next;
    while(cur){
        if (dif > abs(k - cur -> val)){
            res = ind;
            dif = abs(k - cur -> val);
        }
        ind++;
        cur = cur -> next;
    }
    cout << res;
}
// 2 method 
// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     vector<int> v;
//     for(int i = 0; i < n; i++){
//         int num;
//         cin >> num;
//         v.push_back(num);
//     }
//     int k;
//     cin >> k;
//     int mn = 100000;
//     int res = 0;
//     for(int i = 0; i < v.size(); i++){
//         if(abs(k - v[i]) < mn){
//             mn = abs(k - v[i]);
//             res = i;
//         }
//     }
//     cout << res;
// }