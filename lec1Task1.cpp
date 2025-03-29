#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseSentence(const string& sentence) {
    stack<char> s;
    for (char ch : sentence) {
        s.push(ch);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}
int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    reverseSentence(sentence);
    return 0;
}

