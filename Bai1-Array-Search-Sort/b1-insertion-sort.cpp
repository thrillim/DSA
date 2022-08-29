#include <iostream>
using namespace std;

void insertion_sort (int* a, int n) { 
    //sort to increasing order
    for (int i = 1; i < n; i++) {
        int j = i;
        while (a[j] < a[j - 1]) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }
}

int main() {
    int n; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertion_sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}