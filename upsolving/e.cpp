#include<bits/stdc++.h>

using namespace std;

struct MaxHeap{
    vector<long long> heap;

    long long parent(long long i){
        return (i - 1)/2;
    }
    long long left(long long i){
        return 2 * i + 1;
    }
    long long right(long long i){
        return 2 * i + 2;
    }

    void insert(long long val){
        heap.push_back(val);

        long long i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void print(){
        for(int i = 0; i < heap.size(); i++) cout << heap[i] << " ";
    }

    int extractMax(){
        if (heap.size() == 0) return -1;
        if (heap.size() == 1){
            long long root = heap[0];
            // heap.pop_back();
            return root;
        }
        int root = heap[0];
        // heap[0] = heap[heap.size() - 1];
        // heap.pop_back();
        // heapify(0);
        return root;
    }

    void remove(long long val){
        // heap[0] = heap[heap.size() - 1];
        for(int i = 0; i < heap.size(); i++){
            if (heap[i] == val){
                long long ind = i;
                heap[ind] = heap[heap.size() - 1];
                break; 
            }
        }
        heap.pop_back();

        heapify(0);
        // long long i = heap.size() - 1;
        // while(i != 0 && heap[parent(i)] < heap[i]){
        //     swap(heap[parent(i)], heap[i]);
        //     i = parent(i);
        // }
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
};

int main(){
    MaxHeap *maxHeap = new MaxHeap();
    stack<long long> st;
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if (s == "add"){
            long long x;
            cin >> x;
            st.push(x);
            maxHeap -> insert(x);
            // st.pushBack(x);
        }
        else if (s == "delete"){
            if (st.size() > 0){
                int a = st.top();
                maxHeap->remove(a);
                st.pop();
            }
            // st.popBack();
        }
        else if(s == "getmax"){
            if(st.size() > 0)
                cout << maxHeap->extractMax() << endl;
            else cout << "error" << endl;
            // st.getMax();
        }
        else if (s == "getcur"){
            if(st.size() > 0)
                cout << st.top() << endl;
            else cout << "error" << endl;
        }
    }
}