// Problem E. 106183. Database.
#include <bits/stdc++.h>

using namespace std;

struct Node{
    string val;
    Node* next;

    Node(string val){
        this -> val = val;
        next = nullptr;
    }
};

class LinkedList{
    Node* head;
    

public:
    int size;
    LinkedList(){
        head = nullptr;
        size = 0;
    }

    bool contain(string val){
        Node* cur = head;
        while(cur != nullptr){
            if (cur -> val == val){
                return true;
            }
            cur = cur -> next;
        }
        return false;
    }

    void push_back(string val){
        Node* newNode = new Node(val);

        if (!head){
            head = newNode;
        }
        else{
            Node* cur = head;
            if(contain(val)) return; // checking the value for repeating 

            while(cur != nullptr){
                if(cur -> next == nullptr){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }
        }
        size++;
    }
    
    void reverse(){
        Node* next = nullptr;
        Node* prev = nullptr;
        Node* cur = head;

        while(cur != nullptr){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    
    void print(){
        Node* cur = head;
        while(cur != nullptr){
            cout << cur -> val << "\n";
            cur = cur -> next;
        }
    }
};

int main(){
    LinkedList list;
    int n;
    cin >> n;
    string name;
    while(n--){
        
        cin >> name;
        list.push_back(name);
    }
    // list.print();
    list.reverse();
    cout << "All in all: " << list.size << endl;
    cout << "Students:" << endl;
    list.print();
}