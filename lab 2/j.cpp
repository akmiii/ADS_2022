// Problem J. 194847. Find the lost number.
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

public:
    int size;
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
        size++;
    }


    int findNumber(){
        Node* cur = head;
        // Node* cur1 = head -> next;
        while(cur && cur -> next){
            if (abs(cur -> next -> val - cur -> val) > 1){
                int a = (cur -> val) + 1;
                return a;
                
            }
            else if (abs(cur -> val - cur -> next -> val) == 0){
                return cur -> val + 1;
                
            }
            cur = cur -> next;
        } 
    
        if(cur -> val == size) return 0;
        return size;
    }
    
    void sort(){
        Node* first = head;
        Node* second = nullptr;
        while(first -> next != nullptr){
            second = first -> next;
            while(second != nullptr){
                if (first -> val > second -> val){
                    swap(first -> val, second -> val);
                }
                second = second -> next;
            }
            first = first -> next;
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
    vector<int> v;
    while(n--){
        int num;
        cin >> num;
        list.push_back(num);
    }
    
    // list.print();
    list.sort();
    // list.print();
    // cout << endl;
    cout <<  list.findNumber();
    // cout << endl;
    // list.print();
}