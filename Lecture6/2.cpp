#include <bits/stdc++.h>

using namespace std;

// Binary Tree is used for storing information

// Heap
// 2i + 1 (left)  and  2i + 2 (right)
// (i-1) / 2 - parent
// heap -> binHeap: maxHeap, minHeap O(1)
// get - knowing, cut - knowing and cutting

struct Heap{
    int* a;
    int capacity;
    int length;
private:
    void heapUp(int i){
        if (i > 0){
            int p_pos = (i-1) / 2;
            if (a[i] < a[p_pos]){
                swap(a[i], a[p_pos]);
                heapUp(p_pos);
            }
        }
    }

    void heapDown(int i){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int minPos = i;
        if (l < this -> length && a[minPos] > a[l]) minPos = l;
        if (r < this -> length && a[minPos] > a[r]) minPos = r;
        if (i != minPos){
            swap(a[i], a[minPos]);
            heapDown(minPos);
        }
    }

    void cut_Min(){
        a[0] = a[length - 1];
        length = max(length - 1, 0);
        heapDown(0);
    }

    void _add(int x){
        a[length] = x;
        length++;
        heapUp(length - 1);
    }

public:
    Heap(int capacity){
        a = new int[capacity];
        this -> capacity = capacity;
        length = 0;
    }

    int cutMin(){
        int res = a[0];
        cut_Min();
        return res;
    }

    void add(int x){
        _add(x);
    }
    void print(){
        for (int i = 0; i < length; i++){
            cout << a[i] << " ";
        }
    }
};




int main(){
    int a[] = {1, 6, 8, 7, 12, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);

    Heap h(100);

    for (int i= 0; i < n; i++){
        h.add(a[i]);
    }
    // h.print();
    for (int i = 0; i < n; i++){
        cout << h.cutMin() << endl;
        // h.print();
    }
}