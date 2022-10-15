// Ugly numbers

#include <bits/stdc++.h>

using namespace std;

struct Heap{
    int* a;
    bool * user;
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
        if (!user[x]){
            user[x] = true;
            a[length] = x;
            length++;
            heapUp(length - 1);
        }
    }

public:
    Heap(int capacity){
        a = new int[capacity];
        user = new bool[100];
        for (int i = 0; i < 100; i++){
            user[i] = false;
        }
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
    int n;
    cin >> n;
    Heap h(100000);

    h.add(1);
    int x = -1;
    while(n > 0){
        x = h.cutMin();
        h.add(2 * x);
        h.add(3 * x);
        h.add(5 * x);
        n--;
    }
    cout << x;
    // cout << h.cutMin();
}