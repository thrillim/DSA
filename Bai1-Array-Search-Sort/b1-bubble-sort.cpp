#include <iostream>
using namespace std;

void bubble_sort (int* a, int n) {
    //sort to increasing order
    int cntCompare = 0, cntSwap = 0;
    for (int i=0; i<n; i++) { // 1 element is in its correct place at a time
        for (int j=0; j<n-i-1; j++) {
            cntCompare++;
            if (a[j] > a[j+1]) { // compare each pair of elements
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                cntSwap++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << cntCompare << " " << cntSwap << endl;
    }
}

int main() {
    int n; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubble_sort(a, n);
    //for (int i = 0; i < n; i++) {
    //    cout << a[i] << " ";
    //}
    return 0;
}