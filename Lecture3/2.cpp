#include <bits/stdc++.h>

using namespace std;

struct Node{        // совокупность методов и переменных
    int val;
    Node* next;
    Node(int val){  // конструктор
        this -> val = val;
        this -> next = nullptr;
    }
};

// struct LinkedList{
//     Node* head;
// }

int main(){
    Node n(5);
    Node n1(51);

    n.next = &n1;

    Node* cur = &n;
    while(cur){
        cout << cur -> val << " ";
        cur = cur -> next;
    }
}