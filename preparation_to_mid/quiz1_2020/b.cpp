// Problem B. AaAaAaAAaAaAAa
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
public:
    Node* head;
    Node* tail;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if (!head) head = tail = newNode;
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void reverse(){
        Node* prev = nullptr;
        Node* next = nullptr;
        Node* cur = head;

        while(cur){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        tail = head;
        head = prev;
    }

    void print(){
        Node* cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};

int main(){
    int n;
    cin >> n;
    LinkedList list;
    while(n--){
        int num;
        cin >> num;
        if (num == 1){
            int val;
            cin >> val;
            list.push(val);
        }
        if (num == 2){
            list.reverse();
        }
    }
    list.print();
}