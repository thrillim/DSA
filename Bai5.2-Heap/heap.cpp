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

void insert(int heap[], int &n, int x) {
    heap[++n] = x;
    int i = n;
    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}

void remove_max(int heap[], int &n) {
    heap[1] = heap[n--];
    int i = 1;
    while (i * 2 <= n) {
        int j = i * 2;
        if (j + 1 <= n && heap[j + 1] > heap[j]) j++;
        if (heap[i] >= heap[j]) break;
        swap(heap[i], heap[j]);
        i = j;
    }
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
    int x;
    cin >> x;
    insert(heap, n, x);
    print(heap, n);
    remove_max(heap, n);
    print(heap, n);
    return 0;
}