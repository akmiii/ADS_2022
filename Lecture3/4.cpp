#include <bits/stdc++.h>

using namespace std;

struct Node{        // совокупность методов и переменных
    int val;
    Node* next;
    Node* prev;
    Node(int val){  // конструктор
        this -> val = val;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};

struct DoubleLinkedList{
    Node* head;
    Node* tail;

    DoubleLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void push(int x){
        Node* newNode = new Node(x);

        if (!head) head = tail = newNode;
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }
    
    void reversePrint(){
        Node* cur = tail;
        while(cur){
            cout << cur -> val << ' ';
            cur = cur -> prev;
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
    DoubleLinkedList dll;

    for(int i = 0; i < 5; i++) dll.push(i);

    dll.print();
    cout << endl;
    dll.reversePrint();
}

// queuu stack via ll
// lab1 via ll