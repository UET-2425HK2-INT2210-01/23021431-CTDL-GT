#include <iostream> // Thư viện nhập xuất chuẩn

using namespace std;

// Định nghĩa lớp Node đại diện cho một node trong cây nhị phân tìm kiếm
class Node {
public:
    int data; // Giá trị của node
    Node *left; // Con trỏ trỏ đến node con bên trái
    Node *right; // Con trỏ trỏ đến node con bên phải

    // Hàm khởi tạo node với giá trị val, ban đầu không có con
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm chèn một node mới vào cây BST
Node* insertNode(Node *node, int val) {
    if (node == nullptr) { // Nếu cây rỗng hoặc đến vị trí trống, tạo node mới
        return new Node(val);
    }

    // Nếu giá trị nhỏ hơn node hiện tại, chèn vào cây con bên trái
    if (val < node->data) {
        node->left = insertNode(node->left, val);
    } else if (val > node->data) { // Nếu giá trị lớn hơn, chèn vào cây con bên phải
        node->right = insertNode(node->right, val);
    }

    return node; // Trả về root của cây sau khi chèn
}

// Hàm tìm node có giá trị nhỏ nhất trong cây con bên phải (hỗ trợ xoá node)
Node* findMin(Node* root) {
    while (root->left != nullptr) { // Duyệt đến node có giá trị nhỏ nhất
        root = root->left;
    }
    return root;
}

// Hàm xoá node trong cây BST
Node* deleteNode(Node* root, int val) {
    if (!root) return root; // Nếu cây rỗng, không cần xoá

    if (val < root->data) { // Nếu giá trị nhỏ hơn node hiện tại, tìm ở cây con bên trái
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) { // Nếu lớn hơn, tìm ở cây con bên phải
        root->right = deleteNode(root->right, val);
    } else { // Tìm thấy node cần xoá
        if (!root->left) { // Nếu node không có con trái
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) { // Nếu node không có con phải
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Trường hợp node có hai con, thay bằng node nhỏ nhất bên phải
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Hàm in cây theo dạng cây ngang (right -> root -> left)
void printTree(Node* root, int level = 0) {
    if (root) {
        printTree(root->right, level + 1); // In cây con bên phải trước
        for (int i = 0; i < level; i++) { // Tạo khoảng cách để biểu diễn mức của cây
            cout << "    ";
        }
        cout << " -> " << root->data << endl; // In giá trị node
        printTree(root->left, level + 1); // In cây con bên trái sau
    }
}

int main() {
    // Mảng chứa các giá trị để tạo cây BST
    int arr[9] = {2,1,10,6,3,8,7,13,20};
    int add[3] = {14,0,35}; // Các giá trị cần thêm
    int del[3] = {6,13,35}; // Các giá trị cần xoá

    Node *root = nullptr; // Khởi tạo cây rỗng

    // Chèn từng phần tử từ mảng vào cây
    for (int i = 0; i < 9; i++) {
        root = insertNode(root, arr[i]);
    }

    cout << "Cay nhi phan ban dau: " << endl;
    printTree(root);

    // Thêm các phần tử mới vào cây
    for (int i = 0; i < 3; i++) {
        root = insertNode(root, add[i]);
    }

    cout << "Cay nhi phan sau khi them phan tu: " << endl;
    printTree(root);

    // Xoá các phần tử khỏi cây
    for (int i = 0; i < 3; i++) {
        root = deleteNode(root, del[i]);
    }

    cout << "Cay nhi phan sau khi xoa phan tu: " << endl;
    printTree(root);

    system("pause"); // Dừng màn hình để xem kết quả (Windows)
}
