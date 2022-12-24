#include<bits/stdc++.h>
using namespace std;
struct Task {
    string taskName;
    double daysLeft;
    int points;
    int time;
    Task(string taskName, double daysLeft, int points, int time) {
        this->taskName = taskName;
        this->daysLeft = daysLeft;
        this->points = points;
        this->time = time;
    }
};
struct TaskHeap {
    vector<Task*> heap;
    int size;
    TaskHeap() {
        size = 0;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int deadline, int points, int hours){
        heap.push_back()
    }
    void swap(int i, int j) {
        Task* temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    // complete this DS
};
int main() {
    int n;
    cin >> n;
    TaskHeap *heap = new TaskHeap();
    while(n--){
        string s;
        cin >> s;
        if (s == "insert"){
            string task;
            int deadline, points, hours;
            cin >> task >> deadline >> points >> hours;
            heap -> insert();
        }
    }
	// GLHF
}