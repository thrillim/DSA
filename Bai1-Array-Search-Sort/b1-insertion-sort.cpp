#include <iostream>
using namespace std;

// Time: TH xau nhat, tot nhat, trung binh
// Space

// Co break (neu khong thoa man while)
// Time complex:
//     Tot nhat (Xep roi): O(n)
//     Xau nhat (Xep nguoc): O(n^2)
//     Trung binh: O(n^2) (sau nay co cong thuc de tinh)
// Space: 
void insertion_sort (int* a, int n) { 
    //sort to increasing order
    int cntCompare = 0, cntSwap = 0;
    for (int i = 1; i < n; i++) {
        int j = i;
        while (a[j] < a[j - 1]) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
            cntCompare++;
            cntSwap++;
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
    insertion_sort(a, n);
    //for (int i = 0; i < n; i++) {
    //    cout << a[i] << " ";
    //}
    return 0;
}