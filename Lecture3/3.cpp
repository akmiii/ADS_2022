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

struct LinkedList{
    Node* head;
    Node* tail;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void push(int x){
        Node* newNode = new Node(x);

        if (!head) head = tail = newNode;
        else{
            tail -> next = newNode;
            tail = newNode;
        }
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
    LinkedList ll;

    for(int i = 0; i < 5; i++) ll.push(i);

    ll.print();
}