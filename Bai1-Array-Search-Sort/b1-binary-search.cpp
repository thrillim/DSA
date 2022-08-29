#include <iostream>
using namespace std;

int binary_search (int a[], int n, int x) { 
    //array in increasing order
    int left = 0, right = n - 1, mid;    
    while (left < right) {
        mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] > x) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int x, MAX=10, a[MAX], pos;

    cout << "Input " << MAX << " elements in increasing order: ";
    for (int i=0; i<MAX; i++) { cin >> a[i]; }
    cout << "Input your target: "; cin >> x;

    pos = binary_search(a, MAX, x);
    if (pos == -1) { cout << "Not found" << endl; } 
    else {
        cout << "Found at index (base 0): " << pos << endl;
    }
    return 0;
}