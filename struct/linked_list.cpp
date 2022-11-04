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
    int sz;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    void pushBack(int val){
        Node* newNode = new Node(val);
        if (!head) head = tail = new Node(val);
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        sz++;
    }

    void pushFront(int val){
        Node* newNode = new Node(val);
        if (!head) head = tail = new Node(val);
        else{
            newNode -> next = head;
            head = newNode;
        }
        sz++;
    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);
        Node* cur = head;
        int ind = 0;

        if (pos == 0) pushFront(val);
        else{
            while(cur){
                if (ind == pos - 1){
                    newNode -> next = cur -> next;
                    cur -> next = newNode;
                    break;
                }
                ind++;
                cur = cur -> next;
            }
        } 
        sz++;
    }

    void insert2(int val, int pos){
        Node* newNode = new Node(val);
        Node* cur = head;
        if (pos == 0) pushFront(val);
        else if (pos == sz-1) pushBack(val);
        else{
            for (int i = 0; i < pos - 1; i++) cur = cur -> next;
            newNode -> next = cur -> next;
            cur -> next = newNode;
        }
        sz++;
    }

    void popBack(){
        Node* cur = head;
        if (!head){
            cout << "Empty" << endl;
            return;
        }
        while(cur -> next -> next){
            cur = cur -> next;
        }
        cur -> next = nullptr;
        sz--;
    }

    void popBack2(){
        if(sz == 1) head = tail = nullptr;
        else{
            Node* cur = head;
            while(cur -> next -> next){
                cur = cur->next;
            }
            tail = cur;
            cur->next = NULL;
        }
        sz--;
    }

    void pop_back(){
        Node* cur = head;
        if (!head){
            cout << "Empty" << endl;
            return;
        }
        while(cur -> next -> next){
            cur = cur -> next;
        }
        cout << cur -> next -> val << endl;
        cur -> next = nullptr;
        sz--;
    }

    void popFront(){
        Node* cur = head;
        if (!head){
            cout << "Empty" << endl;
            return;
        }
        head = head -> next;
        sz--;
    }

    void pop_front(){
        Node* cur = head;
        if (!head){
            cout << "Empty" << endl;
            return;
        }
        cout << head -> val << endl;
        head = head -> next;
        sz--;
    }

    void deleteByIndex(int pos){
        Node* cur = head;
        int ind = 0;
        if (pos == 0) popFront();
        else if (pos == sz - 1) popBack();
        else{
            while(cur){
                if (ind == pos - 1){
                    cur -> next = cur -> next -> next;
                    break;
                }
                cur = cur -> next;
                ind++;
            }
        }
        sz--;
    }

    void deleteByValue(int val){
        Node* cur = head;
        Node* prev = nullptr;

        if (!head){
            cout << "Empty" << endl;
            return;
        }
        else if (head -> val == val) popFront();
        else{
            while(cur){
                if (cur -> val == val){
                    prev -> next = cur -> next;
                    break;
                }
                prev = cur;
                cur = cur -> next;
            }
        }
        sz--;
    }

    void reverse(){
        Node* cur = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        while(cur){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void updateByIndex(int val, int pos){
        Node* cur = head;
        int ind = 0;
        if (pos == 0) head -> val = val;
        else{
            while(cur){
                if (ind == pos){
                    cur -> val = val;
                }
                cur = cur -> next;
                ind++;
            }
        }
    }

    void search(int val){
        Node* cur = head;
        int ind = 0;
        
        if (!head){
            cout << "Empty" << endl;
            return;
        }
        
        while(cur){
            if (cur -> val == val){
                cout << ind << " ";
            }

            ind++;
            cur = cur -> next;
        }
        cout << endl;
    }

    int get(int pos){
        int ind = 0;
        Node* cur = head;
        if (!head) return -1;
        while(cur){
            if (ind == pos) return cur -> val;
            cur = cur -> next;
            ind++;
        }
    }

    bool contains(int val){
        Node* cur = head;
        if (!head) return false;
        while(cur){
            if (cur -> val == val) return true;
            cur = cur -> next;
        }
        return false;
    }

    Node* shiftLeft(int k){
        Node* cur = head;

        while(cur -> next){
            cur = cur -> next;
        }
        cur -> next = head;
        cur = head;
        for (int i = 0; i < k - 1; i++) cur = cur -> next;
        
        head = cur -> next;
        cur -> next = nullptr;

        return head;
    }

    Node* shiftRight(int k){
        if (k == 0) return head;

        Node* slow = head;
        Node* fast = head;
        
        k %= sz;
        for (int i = 0; i < k; i++) fast = fast -> next;

        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        } 
        fast -> next = head;
        head = slow -> next;
        slow -> next = nullptr;

        return head;
    }

    void bubbleSort(){
        Node *first = head;
        Node *sec = NULL;
        if(head == NULL){
            return;
        }
        while(first->next != NULL){
            sec = first->next;
            while(sec != NULL){
                if(first->val > sec->val){
                    swap(first->val, sec->val);
                }
                sec = sec->next;
            }
            first = first->next;
        }
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

bool isPalindrome(Node* head1, Node* head2){
    Node* cur1 = head1;
    Node* cur2 = head2;

    while(cur1 && cur2){
        if (cur1 -> val != cur2 -> val) return false;
        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }
    return true;
}

Node* merge(Node* lHead, Node* rHead){
    Node* lcur = lHead;
    Node* rcur = rHead;

    Node* head3 = new Node(0);
    Node* cur = head3;

    while(lcur && rcur){
        if (lcur -> val < rcur -> val){
            cur -> next = new Node(lcur -> val);
            lcur = lcur -> next;
        }
        else{
            cur -> next = new Node(rcur -> val);
            rcur = rcur -> next;
        }
        cur = cur -> next;
    }

    if (lcur) cur -> next = lcur;
    else cur -> next = rcur;

    return head3 -> next;
}

Node* sort(Node* head){
    if (!head || !head -> next) return head;

    Node* lHead;
    Node* rHead;

    Node* slow = head;
    Node* fast = head -> next;
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* newHead = slow -> next;
    slow -> next = nullptr;

    lHead = sort(head);
    rHead = sort(newHead);

    return merge(lHead, rHead);
}


int main(){
    LinkedList list;
    LinkedList newLL;
    list.pushBack(1);
    list.pushBack(3);
    list.pushBack(5);
    list.pushFront(2);
    list.pushFront(9);
    list.print();
    list.insert(8, 0);
    list.insert2(7, 2);
    list.insert2(15, 7);
    list.print();
    list.deleteByValue(8);
    list.print();
    list.deleteByIndex(6);
    list.print();
    list.shiftLeft(2);
    list.print();
    list.shiftLeft(1);
    list.print();
    list.shiftRight(1);
    list.print();

    list.popBack();
    list.popFront();
    list.print();
    list.deleteByIndex(2);
    list.print();
    list.deleteByIndex(4);
    list.print();
    list.reverse();
    list.print();
    list.updateByIndex(2, 1);
    list.updateByIndex(8, 0);
    list.print();
    Node* cur = list.head;
    while(cur){
        newLL.pushFront(cur -> val);
        cur = cur -> next;
    }

    if (isPalindrome(list.head, newLL.head)) cout << "YES" << endl;
    else cout << "NO" << endl;

    newLL.search(9);
    list.search(2);
    cout << list.get(0) << endl;

    if (list.contains(0)) cout << "YES" << endl;
    else cout << "NO" << endl;


    LinkedList *sortedLL = new LinkedList();
    Node* newH = sort(list.head);
    sortedLL -> head = newH;
    sortedLL -> print();



    // sort(list.head);
    
}