
#include <iostream>
using namespace std;

int a[10000];
int n;

void quicksort(int l, int r){

    int i = l;
    int j = r;
    int p = a[(l + r) / 2];

    while(i < j){
        while(a[i] < p) i++;   //пока не найдем элемент который больше пивота
        while(a[j] > p) j--;   //пока не найдем элемент который меньше пивота
        if(i <= j){
            swap(a[i], a[j]);
            i++;  //двигаем дальше
            j--;
        }
    }

    if(l < j){   //хотя бы два элемента есть между ними
        quicksort(l, j);
    }  
     
    if (i < r){   //хотя бы два элемента есть между ними
        quicksort(i, r);
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    quicksort(0, n - 1);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}