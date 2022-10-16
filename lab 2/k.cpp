// Problem K. One-time guests
#include <bits/stdc++.h>
using namespace std;

struct Node{
    char val;
    int cnt;
	bool was;
    Node* next;
    Node(char val){
        this->val = val;
		cnt = 0;
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

	void pushBack(char val){
        Node* newNode = new Node(val);
        if (!head){
            head = tail = newNode;
        }
        else{
            Node* cur = head;
            while(cur){
                if(cur -> val == val){
                    cur -> cnt = 1;
                    return;
                }
                cur = cur -> next;
            }
            tail -> next = newNode;
            tail = newNode;
        }
    }

    // bool contains(char val){
    //     Node* cur = head;
    //     while(cur){
    //         if(cur -> val == val){
    //             return true;
    //         }
    //         cur = cur -> next;
    //     }
    //     return false;
    // }

    void print(){
        Node* cur = head;
        while(cur){
            if (cur -> cnt == 0){
                cout << cur -> val << " ";
                return;
            }
            cur = cur -> next;
        }
        cout << "-1 ";

    }
};

int main(){
    int n; 
	cin >> n;
    int x; 
    for(int i = 0; i < n; i++){
        LinkedList ll = LinkedList();
        cin >> x;
        char c;
        while(x--){
            cin >> c;

            ll.pushBack(c);

			ll.print();
        }
		
        cout << endl;

    }
}