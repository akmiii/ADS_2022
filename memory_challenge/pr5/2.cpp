#include <bits/stdc++.h>

using namespace std;

struct MaxHeap{
    vector<int> heap;

    int parent(int i){
        return (i - 1)/2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }

    void insert(int val){
        heap.push_back(val);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    int extractMax(){
        if (heap.size() == 0) return 0;
        if (heap.size() == 1){
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        else{
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
        }
    }

    void heapify(int i){
        int l = left(i), r = right(i);
        int smallest = i;
        if (l < heap.size() && heap[l] > heap[i]) smallest = l;
        if (r < heap.size() && heap[r] > heap[smallest]) smallest = r;
        if (smallest != i){
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }

    void print(){
        for (int i = 0; i < heap.size(); i++) cout << heap[i] << " ";
    }
};

int main(){
    MaxHeap *maxHeap = new MaxHeap;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        maxHeap->insert(x);
    }
    while(maxHeap -> heap.size() > 1){
        int mx1 = maxHeap -> extractMax();
        int mx2 = maxHeap -> extractMax();
        if (mx1 != mx2){
            maxHeap -> insert(mx1 - mx2);
        }
    }
    
    cout << maxHeap -> extractMax();
}