#include <iostream>
#include <stack>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    stack<int> st;
    while (n != 0) {
        st.push(m % n);
        m = n;
        n = st.top();
        st.pop();
    }
    cout << m << endl;
    return 0;
}
