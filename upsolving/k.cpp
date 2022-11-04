#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    // bool isRev;
    Node* next;
    Node* prev;

    Node(int val){
        this -> val = val;
        // isRev = false;
        next = prev = nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    int sz;
    bool isRev;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        sz = 0;
        isRev = false;
    }

    void pushBack(int val){
        Node* newNode = new Node(val);

        if (!tail){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        sz++;
    }

    void pushFront(int val){
        Node* newNode = new Node(val);

        if (!head) head = tail = newNode;
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void popBack(){
        if (tail){
            tail = tail -> prev;
            if (tail) tail -> next = nullptr;
            else head = nullptr;
        }
        sz--;
    }

    void print_n(){
        Node* cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << endl;
    }
    void print_p(){
        Node* cur = tail;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> prev;
        }
        cout << endl;
    }

    void reverseList(Node* head){
        Node* left = head, * right = tail;
    
        while (left != right && left->prev != right) {
    
            // Swap data of left and right pointer
            swap(left->val, right->val);
    
            // Advance left pointer
            left = left->next;
    
            // Advance right pointer
            right = right->prev;
        }
    }
};

int main(){
    LinkedList list;
    int n;
    cin >> n;
    int cnt = 0;
    bool ok = false;
    while(n--){
        int command;
        cin >> command;
        
        if (command == 1){
            int val;
            cin >> val;
            if (ok == false)
                list.pushBack(val);
            else list.pushFront(val);
            
        }
        if (command == 2){
            ok = !ok;
            // list.reverseList(list.head);
            // int val = list.tail-> val;
            // list.pushFront(val);
            // list.popBack();

        }
    }
    // cout << list.head -> val<< ' ' << list.tail -> val << endl;
    if (ok)
        list.print_p();
    else list.print_n();
}

/*
bool ok = false;

1. 2->3
2. 3->2
1. 3->2->4->5
2. 5->4->3->2

*/