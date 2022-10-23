// Problem C. Standard problem about soccer
#include <bits/stdc++.h>

using namespace std;

struct MaxHeap {
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
        while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    unsigned long long extactMax() {
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
    void heapify(unsigned long long i) {
        unsigned long long l = this->left(i);
        unsigned long long r = this->right(i);
        unsigned long long smallest = i;
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
    unsigned long long n, x;
    cin >> n >> x;
    while(n--){
        int num;
        cin >> num;
        maxHeap -> insert(num);
    }
    unsigned long long sum = 0;
    for (int i = 0; i < x; i++){
        int mx1 = maxHeap -> extactMax();
        sum += mx1;
        maxHeap -> insert(mx1 - 1);
    }

    cout << sum;

}