// Problem D. Experiment with Mixtures
#include <bits/stdc++.h>

using namespace std;

struct MinHeap {
    vector<unsigned long long> heap;

    unsigned long long parent(unsigned long long i) {
        return (i - 1) / 2;
    }
    unsigned long long left(unsigned long long i) {
        return 2 * i + 1;
    }
    unsigned long long right(unsigned long long i) {
        return 2 * i + 2;
    }
    void insert(unsigned long long value) {
        this->heap.push_back(value);
        unsigned long long i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    unsigned long long extactMin() {
        if (this->heap.size() == 0) return 0;
        if (this->heap.size() == 1) {
            unsigned long long root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        unsigned long long root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }
    unsigned long long getMin(){
        return this -> heap[0];
    }
    void heapify(int i) {
        unsigned long long l = this->left(i);
        unsigned long long r = this->right(i);
        unsigned long long smallest = i;
        if (l < this->heap.size() && this->heap[l] < this->heap[i])
            smallest = l;
        if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
            smallest = r;
        if (smallest != i) {
            swap(this->heap[i], this->heap[smallest]);
            this->heapify(smallest);
        }
    }
};

int main(){
    MinHeap * minHeap = new MinHeap();
    unsigned long long n, k;
    cin >> n >> k;

    while(n--){
        int x;
        cin >> x;
        minHeap->insert(x);
    }
    unsigned long long sum = 0;
    unsigned long long cnt = 0;
    if (minHeap -> getMin() > k){
        cout << 0;
        return 0;
    }
    while(minHeap->heap.size() > 1 && minHeap->getMin() < k){

        unsigned long long mn1 = minHeap->extactMin();
        unsigned long long mn2 = minHeap->extactMin();
        
        minHeap->insert((mn1 + 2 * mn2));
        sum = mn1 + 2 * mn2;
        cnt++; 
    }
    if (sum < k) cout << -1;
    else cout << cnt;
}