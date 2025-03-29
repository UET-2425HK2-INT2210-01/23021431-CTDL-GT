#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

// Hàm in cây heap theo dạng trực quan
void printTree(const vector<int>& heap) {
    int levels = log(heap.size()) / log(2) + 1; // Tính số mức của cây heap
    int index = 0;
    int width = pow(2, levels) * 2; // Xác định chiều rộng hiển thị

    for (int i = 0; i < levels; i++) {
        int nodes = pow(2, i); // Số node ở mỗi mức
        int space = width / (nodes + 1); // Khoảng cách giữa các node

        for (int j = 0; j < nodes && index < heap.size(); j++) {
            cout << setw(space) << heap[index++] << setw(space) << " "; // Hiển thị node với khoảng cách phù hợp
        }
        cout << endl; // Xuống dòng sau mỗi mức
    }
}

// Hàm chuyển đổi priority_queue (maxHeap) thành vector để dễ in ra màn hình
vector<int> convertHeapVector(priority_queue<int> maxHeap) {
    vector<int> heapVector;

    while (!maxHeap.empty()) {
        heapVector.push_back(maxHeap.top()); // Lấy phần tử lớn nhất
        maxHeap.pop(); // Loại bỏ phần tử vừa lấy
    }

    return heapVector;
}

int main() {
    // Mảng đầu vào để khởi tạo heap
    int arr[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0])); // Chuyển mảng thành vector

    priority_queue<int> maxHeap; // Khởi tạo priority queue dạng max heap

    // Thêm phần tử vào heap từ danh sách nums
    for (int num : nums) {
        maxHeap.push(num); // Đẩy vào heap
    }

    // Chuyển heap thành vector để in ra
    vector<int> printVector = convertHeapVector(maxHeap);
    cout << "Heap Tree sau khi them cac phan tu: " << endl;
    printTree(printVector);

    // Danh sách các phần tử cần thêm vào heap
    int add[] = {14, 0, 35};
    vector<int> newNodes(add, add + sizeof(add) / sizeof(add[0]));

    // Thêm các phần tử mới vào heap
    for (int num : newNodes) {
        maxHeap.push(num);
    }

    // In ra cây heap sau khi thêm phần tử
    vector<int> addVector = convertHeapVector(maxHeap);
    cout << "Heap Tree sau khi them 3 phan tu: " << endl;
    printTree(addVector);

    // Danh sách các phần tử cần xoá khỏi heap
    int remv[] = {6, 13, 15};
    vector<int> removeNodes(remv, remv + sizeof(remv) / sizeof(remv[0]));

    vector<int> tempHeap; // Mảng tạm để lưu heap sau khi loại bỏ phần tử

    // Xoá các phần tử theo danh sách removeNodes
    while (!maxHeap.empty()) {
        int top = maxHeap.top(); // Lấy phần tử lớn nhất
        maxHeap.pop(); // Loại bỏ phần tử vừa lấy

        // Nếu phần tử không nằm trong danh sách xoá, giữ lại
        if (find(removeNodes.begin(), removeNodes.end(), top) == removeNodes.end()) {
            tempHeap.push_back(top);
        }
    }

    // Tạo lại heap từ danh sách còn lại
    for (int num : tempHeap) {
        maxHeap.push(num);
    }

    // Chuyển heap thành vector để in ra
    vector<int> delVector = convertHeapVector(maxHeap);
    cout << "Heap Tree sau khi xoa cac phan tu: " << endl;
    printTree(delVector);

    system("pause"); // Dừng màn hình trên Windows
}
