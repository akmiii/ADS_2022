// Problem F. 103826. Insertion of Node.
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
    Node* head;
    int size;

public:
    LinkedList(){
        head = nullptr;
        size = 0;
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if (!head){
            head = newNode;
        }
        else{
            Node* cur = head;
            while(cur != nullptr){
                if (cur -> next == nullptr){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }
        }
    }
    
    void push_front(int val){
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else{
            newNode -> next = head;
            head = newNode;
        }
        size++;
    }

    void insert(int pos, int val){
        Node* newNode = new Node(val);
        Node* cur = head;
        int i = 0;

        if (pos == 0) push_front(val);
        else{
            while(cur != nullptr){
                if (i == pos - 1){
                    newNode -> next = cur -> next;
                    cur -> next = newNode;
                    break;
                }
            cur = cur -> next;
            i++;
            }
        } 
    }
    
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
    // list.print();
    int data, ind;
    cin >> data >> ind;
    list.insert(ind, data);
    list.print();
}