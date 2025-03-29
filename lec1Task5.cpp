#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    for (int i = 0; i < 5; i++) {
        double x;
        cin >> x;
        maxHeap.push(x);
        minHeap.push(x);
    }
    cout << maxHeap.top() + minHeap.top();
    return 0;
}
