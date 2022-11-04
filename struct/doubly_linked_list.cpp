#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this -> val = val;
        next = prev = nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    int sz;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    void pushBack(int val){
        Node* newNode = new Node(val);
        sz++; 

        if (!head){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    // void pushBack2(int val){
    //     Node* newNode = new Node(val);

    //     if (!head){
    //         head = tail = newNode;
            
    //     }
    //     else{
    //         Node* cur = head;
    //         while(cur){
    //             if (cur -> next == nullptr){
    //                 cur -> next = newNode;
    //                 newNode -> prev = cur;
    //                 break;
    //             }
    //             cur = cur -> next;
    //         }
    //     }
    //     sz++;
    // }

    void pushFront(int val){
        Node* newNode = new Node(val);
        sz++;

        if (!head) head = tail = newNode;
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);
        int ind = 0;
        Node* cur = head;

        if (pos == 0) pushFront(val);
        else if (pos == sz) pushBack(val);
        else{
            while(cur){
                if (ind == pos - 1){
                    cur -> next -> prev = newNode;
                    newNode -> next = cur -> next;
                    cur -> next  = newNode;
                    newNode -> prev = cur;
                    break;
                }
                ind++;
                cur = cur -> next;
            }
            sz++;
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

    void popFront(){
        if (head){
            head = head -> next;
            if (head) head -> prev = nullptr;
            else tail = nullptr;
        }
        
        sz--;
    }

    void deleteByIndex(int pos){
        if (pos < 0 || pos >= sz){
            cout << "Error" << endl;
            
        }

        Node* cur = head;
        int ind = 0;

        if (pos == 0)
            popFront();
        
        else if (pos == sz - 1) 
            popBack();

        else{
            while(cur){
                if (ind == pos){
                    cur -> prev -> next = cur -> next;
                    cur -> next -> prev = cur -> prev;
                    // cur -> next = cur -> next -> next;
                }
                cur = cur -> next;
                ind++;
            }
            sz--;
        }
    }

    void deleteByValue(int val){
        Node* cur = head;
        if (!head){
            cout << "Empty" << endl;
            return;
        }
        else if(head -> val == val) popFront();
        else if(tail -> val == val) popBack();
        else{
            while(cur){
                if (cur -> val == val){
                    cur -> next -> prev = cur -> prev;
                    cur -> prev -> next = cur -> next;
                    break;
                }
                cur = cur -> next;
            }
            sz--;
        }
    }

    void updateValue(int val, int pos){
        Node* cur = head;
        int ind = 0;
        while(cur){
            if (pos == ind){
                cur -> val = val;
                break;
            }
            cur = cur -> next;
            ind++;
        }
    }
    void reverse(){
        Node* temp = tail;
        while(temp){
            cout << temp -> val << " ";
            temp = temp -> prev;
        }
        cout << endl;
    }

    int get(int pos){
        int ind = 0;
        Node* cur = head;
        while(cur){
            if(ind == pos) return cur -> val;

            ind++;
            cur = cur -> next;
        }
    }
    
    void getPrev(int pos){
        if (pos == 0){
            cout << "No prev value" << endl;
            return;
        }
        int ind = 0;
        Node* cur = head;
        while(cur){
            if(ind == pos) cout << cur -> prev -> val << endl;

            ind++;
            cur = cur -> next;
        }
    }

    void getNext(int pos){
        if (pos == sz - 1){
            cout << "No next value" << endl;
            return;
        }

        int ind = 0;
        Node* cur = head;
        while(cur){
            if(ind == pos) cout << cur -> next -> val << endl;

            ind++;
            cur = cur -> next;
        }
    }

    int getSize(){
        return sz;
    }

    void print(){
        Node* cur = head;
        while(cur){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(5);
    list.print();
    list.pushFront(3);
    list.pushFront(12);
    // list.print();
    // // cout << list.getSize() << endl;
    list.insert(10, 0);
    
    list.print();
    list.insert(11, 6);
    list.insert(7, 3);
    list.print();
    // cout << list.getSize() << endl;
    
    list.popBack();
    list.print();
    list.popFront();
    list.print();
    // list.getPrev(0);
    // list.getNext(0);
    // // cout << list.get(3) << endl;
    // cout << list.getSize() << endl;
    list.deleteByIndex(0);
    list.print();
    list.deleteByValue(7);
    list.deleteByValue(5);
    list.print();
    list.reverse();
    list.print();
    list.updateValue(7, 0);
    list.print();
}