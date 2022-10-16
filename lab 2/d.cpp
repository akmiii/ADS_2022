// Problem D. 143619. List modes.
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    int cnt;
    Node* next;

    Node(int val){
        this -> val = val;
        cnt = 1;
        next = nullptr;
    }
};

class LinkedList{
    Node* head;
    int size;

public:
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
                if (cur -> val == val){
                    cur -> cnt++;
                    break;
                }

                if (cur -> next == nullptr){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }
        }
    }
    
    int findMax(){
        Node* cur = head;
        int mx = 1;

        while(cur != nullptr){
            if (cur -> cnt > mx) mx = cur -> cnt;

            cur = cur -> next;
        }
        return mx;
    }

    void print(){
        vector<int> v;
        Node* cur = head;
        while(cur != nullptr){
            if (cur -> cnt == findMax()) v.push_back(cur -> val);
            cur = cur -> next;
        }
        
        sort(v.begin(), v.end());
        for (int i = v.size()-1; i >= 0; i--) cout << v[i] << " ";
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

    list.print();
}