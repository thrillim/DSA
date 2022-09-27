// Ứng dụng: hàng đợi ưu tiên
// Ví dụ: Khách hạng thương gia được ưu tiên (+1000) hơn khách hàng thường (đánh số lần lượt)
// Khách 1st class (+100000)

// => Đánh số ngược (dùng max-heap)
// => -1000 (dùng min-heap)

#include <iostream>
#include <string>
using namespace std;

// min-heap
void upHeap(int a[], int i) {
    int key = a[i];
    while (i > 1 && key < a[i / 2]) {
        a[i] = a[i / 2];
        i /= 2;
    }
    a[i] = key;
}

void downHeap(int a[], int i, int n) {
    int key = a[i];
    while (i <= n / 2) {
        int j = 2 * i;
        if (j < n && a[j] > a[j + 1]) j++;
        if (key <= a[j]) break;
        a[i] = a[j];
        i = j;
    }
    a[i] = key;
}

void print(int heap[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void getMin(int heap[], int &n) {
    cout << heap[1] << " ";
    swap(heap[1], heap[n--]);
    downHeap(heap, 1, n);
}

struct Customer {
    string name;
    int priority;
};

int main() {
    int MAX;
    cout << "Max available seats: ";
    cin >> MAX;
    int numOfCustomer;
    cout << "Number of customers: ";
    cin >> numOfCustomer;
    Customer *customer = new Customer[numOfCustomer];
    string typeOfSeat;
    for (int i = 0; i < numOfCustomer; i++) {
        cout << "Customer " << i + 1 << endl;
        cout << "Name: ";
        cin >> customer[i].name;
        cout << "Type of seat ((f)irst, (b)usiness, (e)conomy): ";
        cin >> typeOfSeat;
        if (typeOfSeat == "f") {
            customer[i].priority = -MAX*100000 - i - 1;
        } else if (typeOfSeat == "b") {
            customer[i].priority = -MAX*1000 - i - 1;
        } else if (typeOfSeat == "e") {
            customer[i].priority = i + 1;
        }
    }
    int *heap = new int[MAX + 1];
    int n = 0;
    for (int i = 0; i < numOfCustomer; i++) {
        heap[++n] = customer[i].priority;
        upHeap(heap, n);
    }
    cout << "Heap: ";
    print(heap, n);
    cout << "Order: ";
    for (int i = 0; i < numOfCustomer; i++) {
        getMin(heap, n);
    }
}