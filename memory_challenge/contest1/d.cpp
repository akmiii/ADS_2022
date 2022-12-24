#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
};

struct LinkedList {
    ListNode* head;
    LinkedList(): head(nullptr) {}
    void add(int x) {
        ListNode* node = new ListNode(x);
        if (head == nullptr) {
            head = node;
        } else {
            ListNode* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = node;
        }
    }
  
    void kill(int n, int k) {
        ListNode* cur = head;
        int ind = n-1;
        while(cur){
            if (n - k == 0){
                head = head -> next;
                break;
            }
            if (ind == k){
                cur -> next = cur -> next -> next;
                break;
            }
            ind--;
            cur = cur -> next;
        }
        // your code is here
    }
  
    void print() {
        ListNode* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    LinkedList list;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        list.add(num);
    }
    list.kill(n, k);
    list.print();
    // and here
    return 0;
}