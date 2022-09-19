#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    // Con trỏ đến con tiếp theo cùng cha (lớn hơn)
    Node* nextSibling;

public:
    Node() {
        data = 0;
        fatherNode = NULL;
        firstChild = NULL;
        nextSibling = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Node(int data) {
        this->data = data;
        fatherNode = NULL;
        firstChild = NULL;
        nextSibling = NULL;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        root = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Tree(int data) {
        root = new Node(data);
    }

    // Hàm tìm Node có giá trị data và trả về con trỏ đến Node đó (nếu có)
    Node* findNode(int data) {
        if (root == NULL) {
            return NULL;
        }
        Node* currentNode = root;
        while (currentNode != NULL) {
            if (currentNode->data == data) {
                return currentNode;
            }
            if (currentNode->firstChild != NULL) {
                currentNode = currentNode->firstChild;
                continue;
            }
            if (currentNode->nextSibling != NULL) {
                currentNode = currentNode->nextSibling;
                continue;
            }
            while (currentNode->fatherNode != NULL) {
                currentNode = currentNode->fatherNode;
                if (currentNode->nextSibling != NULL) {
                    currentNode = currentNode->nextSibling;
                    break;
                }
            }
        }
        return NULL;
    }

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        // Nếu cây rỗng
        if (root == NULL) {
            return false;
        } else {
            Node* fatherNode = findNode(father);
            // Nếu không tìm thấy Node cha
            if (fatherNode == NULL) {
                return false;
            } else {
                // Nếu Node cha đã có con là data
                Node* currentNode = fatherNode->firstChild;
                while (currentNode != NULL) {
                    if (currentNode->data == data) {
                        return false;
                    }
                    currentNode = currentNode->nextSibling;
                }
                // Tạo Node mới
                Node* newNode = new Node(data);
                newNode->fatherNode = fatherNode;
                // Nếu Node cha chưa có con
                if (fatherNode->firstChild == NULL) {
                    fatherNode->firstChild = newNode;
                } else {
                    // Nếu Node cha đã có con
                    currentNode = fatherNode->firstChild;
                    while (currentNode->nextSibling != NULL &&currentNode->nextSibling->data < data) {
                        currentNode = currentNode->nextSibling;
                    }
                    newNode->nextSibling = currentNode->nextSibling;
                    currentNode->nextSibling = newNode;
                }
                return true;
            }
        }

    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data) {
        // Nếu cây rỗng
        if (root == NULL) {
            return 0;
        } else {
            Node* currentNode = findNode(data);
            // Nếu không tìm thấy Node
            if (currentNode == NULL) {
                return 0;
            } else {
                // Nếu Node là Node lá
                if (currentNode->firstChild == NULL) {
                    // Nếu Node là Node gốc
                    if (currentNode->fatherNode == NULL) {
                        root = NULL;
                    } else {
                        // Nếu Node là con đầu tiên của cha
                        if (currentNode->fatherNode->firstChild == currentNode) {
                            currentNode->fatherNode->firstChild = currentNode->nextSibling;
                        } else {
                            // Nếu Node là con thứ 2 trở đi của cha
                            Node* tempNode = currentNode->fatherNode->firstChild;
                            while (tempNode->nextSibling != currentNode) {
                                tempNode = tempNode->nextSibling;
                            }
                            tempNode->nextSibling = currentNode->nextSibling;
                        }
                    }
                    delete currentNode;
                    return 1;
                } else {
                    // Nếu Node không phải là Node lá
                    // Xoá Node đó và toàn bộ các Node con của nó
                    int count = 0;
                    // Xoá các Node con của Node đó
                    Node* tempNode = currentNode->firstChild;
                    while (tempNode != NULL) {
                        count += remove(tempNode->data);
                        tempNode = currentNode->firstChild;
                    }
                    // Xoá Node đó
                    // Nếu Node là Node gốc
                    if (currentNode->fatherNode == NULL) {
                        root = NULL;
                    } else {
                        // Nếu Node là con đầu tiên của cha
                        if (currentNode->fatherNode->firstChild == currentNode) {
                            currentNode->fatherNode->firstChild = currentNode->nextSibling;
                        } else { 
                            // Nếu Node là con thứ 2 trở đi của cha
                            tempNode = currentNode->fatherNode->firstChild;
                            while (tempNode->nextSibling != currentNode) {
                                tempNode = tempNode->nextSibling;
                            }
                            tempNode->nextSibling = currentNode->nextSibling;
                        }
                    }
                    delete currentNode;
                    return count + 1;
                }
            }
        }
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder() {
        // Nếu cây rỗng
        if (root == NULL) {
            cout << "Tree is empty" << endl;
        } 
        Node* currentNode = root;
        cout << currentNode->data << " ";
        while (currentNode != NULL) {
            if (currentNode->firstChild != NULL) {
                currentNode = currentNode->firstChild;
                cout << currentNode->data << " ";
            } else {
                while (currentNode->nextSibling == NULL && currentNode->fatherNode != NULL) {
                    currentNode = currentNode->fatherNode;
                }
                if (currentNode->fatherNode == NULL) {
                    break;
                }
                currentNode = currentNode->nextSibling;
                cout << currentNode->data << " ";
            }
        }
        cout << endl;
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder() {
        // Nếu cây rỗng
        if (root == NULL) {
            cout << "Tree is empty" << endl;
        } 
        Node* currentNode = root;
        while (currentNode != NULL) {
            if (currentNode->firstChild != NULL) {
                currentNode = currentNode->firstChild;
            } else {
                cout << currentNode->data << " ";
                while (currentNode->nextSibling == NULL && currentNode->fatherNode != NULL) {
                    currentNode = currentNode->fatherNode;
                    cout << currentNode->data << " ";
                }
                if (currentNode->fatherNode == NULL) {
                    break;
                }
                currentNode = currentNode->nextSibling;
            }
        }
        cout << endl;
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        // Nếu cây rỗng
        if (root == NULL) {
            return true;
        } else {
            Node* currentNode = root;
            while (currentNode != NULL) {
                if (currentNode->firstChild != NULL) {
                    currentNode = currentNode->firstChild;
                } else {
                    while (currentNode->nextSibling == NULL && currentNode->fatherNode != NULL) {
                        currentNode = currentNode->fatherNode;
                    }
                    if (currentNode->fatherNode == NULL) {
                        break;
                    }
                    currentNode = currentNode->nextSibling;
                    if (currentNode->nextSibling != NULL) {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
        // Nếu không là cây nhị phân
        if (!this->isBinaryTree()) {
            return false;
        } else {
            // Nếu cây rỗng
            if (root == NULL) {
                return true;
            } else {
                Node* currentNode = root;
                while (currentNode != NULL) {
                    if (currentNode->firstChild != NULL) {
                        if (currentNode->data < currentNode->firstChild->data) {
                            return false;
                        }
                        currentNode = currentNode->firstChild;
                    } else {
                        while (currentNode->nextSibling == NULL && currentNode->fatherNode != NULL) {
                            currentNode = currentNode->fatherNode;
                        }
                        if (currentNode->fatherNode == NULL) {
                            break;
                        }
                        currentNode = currentNode->nextSibling;
                        if (currentNode->data < currentNode->fatherNode->data) {
                            return false;
                        }
                    }
                }
                return true;
            }
        }
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree();

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder();

    // Hàm trả về độ cao của cây
    int height();

    // Hàm trả về độ sâu của một Node
    int depth(int data);

    // Hàm đếm số lượng lá
    int numOfLeaves();

    // Hàm trả về Node có giá trị lớn nhất
    int findMax();

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild();
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    Tree * tree = new Tree(4);
    tree->insert(4, 2);
    tree->insert(4, 8);
    tree->insert(2, 1);
    tree->insert(2, 3);
    //tree->insert(2, 16);
    tree->insert(8, 6);
    tree->insert(8, 15);
    //tree->remove(3);
    // Test thử các hàm của lớp cây
    tree->preorder();
    tree->postorder();
    cout << tree->isBinaryTree() << endl;
    cout << tree->isBinarySearchTree() << endl;
    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}