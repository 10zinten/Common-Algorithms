#include<iostream>
using namespace std;

void exch(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int Partitioin(int a[], int lo, int hi) {
    int i = lo, j = hi+1;
    while(true) {
        while(a[++i] < a[lo])    // Find item on left to swap
            if(i == hi) break;
        while(a[--j] > a[lo])    // Find item on right to swap
            if(j == lo) break;
        if(i >= j) break;        // Check if the pointer swap
        exch(a, i, j);
    }
    exch(a, lo, j);              // Swap with partition item
    return j;                    // return index of item now known to be in place
}

void Sort(int a[], int lo, int hi) {
    if(hi <= lo) return;
    int j = Partitioin(a, lo, hi);
    Sort(a, lo, j - 1);
    Sort(a, j + 1, hi);
}

int main() {
    int a[] = {6, 3, 7, 9, 5, 1, 4};
    int s = sizeof(a)/sizeof(int);
    Sort(a, 0, s - 1);

    for(int i = 0; i < s; i++)
        cout<<a[i]<<" ";
}
