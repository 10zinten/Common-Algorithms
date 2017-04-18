#include<iostream>
using namespace std;

void Merge(int a[], int aux[], int lo, int mid, int hi) {
    for(int k = lo; k <= hi; k++)
        aux[k] = a[k];

    int i = lo, j = mid + 1;
    for(int k = lo; k <= hi; k++) {
        if(i > mid)                 a[k] = aux[j++];
        else if(j > hi)             a[k] = aux[i++];
        else if(aux[j] > aux[i])    a[k] = aux[i++];
        else                        a[k] = aux[j++];
    }
}

void Sort(int a[], int aux[], int lo, int hi) {
    if(hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    Sort(a, aux, lo, mid);
    Sort(a, aux, mid + 1, hi);
    Merge(a, aux, lo, mid, hi);
}

int main() {
    int a[] = {6, 3, 7, 9, 5, 1, 5};
    int s = sizeof(a)/sizeof(int);
    int aux[s];
    Sort(a, aux, 0, s - 1);

    for(int i = 0; i < s; i++)
        cout<<a[i]<<" ";
}
