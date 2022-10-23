// Problem B. Rock Game
#include <bits/stdc++.h>

using namespace std;

struct MaxHeap {
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    void insert(int value) {
        this->heap.push_back(value);
        int i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    int extactMax() {
        if (this->heap.size() == 0) return 0;
        if (this->heap.size() == 1) {
            int root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        int root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }
    void heapify(int i) {
        int l = this->left(i);
        int r = this->right(i);
        int smallest = i;
        if (l < this->heap.size() && this->heap[l] > this->heap[i])
            smallest = l;
        if (r < this->heap.size() && this->heap[r] > this->heap[smallest])
            smallest = r;
        if (smallest != i) {
            swap(this->heap[i], this->heap[smallest]);
            this->heapify(smallest);
        }
    }
};

int main(){
    MaxHeap * maxHeap = new MaxHeap();
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        maxHeap->insert(x);
    }
    while(maxHeap -> heap.size() > 1){
        int mx1 = maxHeap->extactMax();
        int mx2 = maxHeap->extactMax();
        if (mx1 != mx2){
            maxHeap->insert((mx1 - mx2));
        }
    }
    cout << maxHeap -> extactMax();
}