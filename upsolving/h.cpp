#include<bits/stdc++.h>

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

    void print(){
        for(int i = 0; i < heap.size(); i++) cout << heap[i] << " ";
    }

    int extractMax(){
        if (heap.size() == 0) return 0;
        if (heap.size() == 1){
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }

    void heapify(int i){
        int l = left(i), r = right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] > heap[i]) smallest = l;
        if (r < heap.size() && heap[r] > heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    int getRes(int i){
        int l = left(i), r = right(i);
        int cnt = 0;

        if (l < heap.size() && r < heap.size() && heap[l] < heap[r]) cnt++;

        return cnt;
    }
};

int main(){
    MaxHeap *maxHeap = new MaxHeap();
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        maxHeap->insert(x);
    }
    
    int cnt = 0;
    for(int i = 0; i < maxHeap -> heap.size(); i++){
        cnt += maxHeap->getRes(i);
    }

    cout << cnt;
}
