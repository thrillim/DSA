// Kiểm tra có phải cây nhị phân hoàn hảo không

// Cách cồng kềnh: Đánh số các nút trên cây theo kiểu nhị phân
// Root: 1
//     /   \
//   10     11
//  /  \   /  \
// 100 101 110 111
// ...
// Nếu có nút nào đó rỗng thì cây không phải là nhị phân hoàn hảo
// Chưa hiểu cách nì

// Cách khác: Dùng mảng

// Các thao tác trên heap: thêm, xóa

#include <iostream>
using namespace std;

void upHeap(int a[], int i) {
    int key = a[i];
    while (i > 1 && key > a[i / 2]) {
        a[i] = a[i / 2];
        i /= 2;
    }
    a[i] = key;
}

void downHeap(int a[], int i, int n) {
    int key = a[i];
    while (i <= n / 2) {
        int j = 2 * i;
        if (j < n && a[j] < a[j + 1]) j++;
        if (key >= a[j]) break;
        a[i] = a[j];
        i = j;
    }
    a[i] = key;
}

void heapify(int heap[], int n) {
    // Downheap from leaf (leaf not need to down)
    // Complexity: O(n/2 * log(n/2)) = O(nlogn)
    for (int i = n / 2; i >= 1; i--) {
        downHeap(heap, i, n);
    }
}

void insert(int heap[], int &n, int x) {
    heap[++n] = x;
    int i = n;
    upHeap(heap, i);
}

void remove_max(int heap[], int &n) {
    heap[1] = heap[n--];
    downHeap(heap, 1, n);
}

void print(int heap[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int MAX = 100;
    int heap[MAX];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> heap[i];
    }
    print(heap, n);
    heapify(heap, n);
    print(heap, n);
    return 0;
}