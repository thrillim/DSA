#include <iostream>
using namespace std;

void selection_sort (int* a, int n) {
    int min, temp;
    for (int i = 0; i < n; i++) {
        min = a[i];
        for (int j = i + 1; j < n; j++) {
            if (a[j] < min) {
                min = a[j];
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    selection_sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}