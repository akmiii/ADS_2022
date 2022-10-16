// Problem G. 160416. Height checker.
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
    LinkedList(){
        head = nullptr;
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
    
    int compareLists(Node* head, Node* head1){
        Node* cur = head;
        Node* cur1 = head1;
        int cnt = 0;
        while(cur && cur1){
            if (cur ->val != cur1 -> val) cnt++;
            cur = cur -> next;
            cur1 = cur1 -> next;
        }
        return cnt;
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
    LinkedList sortedList;
    int num;
    while(cin >> num){
        list.push_back(num);
        sortedList.push_back(num);
    }
    sortedList.sort();
    cout << list.compareLists(list.head, sortedList.head);
}