#include <iostream>
using namespace std;

int linear_search(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int x, MAX=10;
    int a[MAX];
    cout << "Input " << MAX << " elements: ";
    for (int i=0; i<MAX; i++) {
        cin >> a[i];
    }
    cout << "Input your target: ";
    cin >> x;
    int pos = linear_search(a, MAX, x);
    if (pos == -1) {
        cout << "Not found" << endl;
    } else {
        cout << "Found at index (base 0): " << pos << endl;
    }
    return 0;
}