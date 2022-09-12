#include <iostream>
using namespace std;

// Time: TH xau nhat, tot nhat, trung binh
// Space

// Khong co break trong vong for nen se duyet het 
// Time complex: O(n^2) Khong co TH xau nhat hay tot nhat
// Space complex: O(n+2) = O(n)
void selection_sort (int* a, int n) {
    int min, temp, cntCompare = 0, cntSwap = 0;
    for (int i = 0; i < n; i++) {
        min = a[i];
        for (int j = i + 1; j < n; j++) {
            cntCompare++;
            if (a[j] < min) {
                min = a[j];
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
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
    selection_sort(a, n);
    //for (int i = 0; i < n; i++) {
    //    cout << a[i] << " ";
    //}
    return 0;
}