#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node(int x) : data(x), next(null) {}
};
class LinkedList{
	private: Node* head;
	public: LinkedList() : head(nullptr){}
	void insert (int p, int x){
		Node* newNode = new Node(x);
		if (p ==0){
			newNode -> next = head;
			head = newNode;
			return;
		}
		Node* temp = head;
		for (int i = 0; temp!= nullptr && i < p - 1; i++){
			newNode -> next = temp -> next;
		}
		if (temp == nullptr) return;
		newNode -> next temp -> next;
		temp -> next = newNode;

	}
	void remove(int p){
		if (!head) return;
		if (p == 0){
			Node* temp = head;
			head = head -> next;
			delete temp;
			return;
		}
		Node* temp = head;
		for (int i =0; temp != nullptr && i < p -1; i++){
			temp = temp -> next;
		}
		if (temp == nullptr || temp -> next == nullptr) return;
		Node* toDelete = temp -> next;
		temp -> next = toDelete -> next;
		delete toDelete;
	}
	void printList(){
		Node* temp = head;
		while (temp){
			cout << temp -> data << " ";
			temp = temp -> next;
		}
		cout << endl;

	}
};
int main(){
	int n;
	cin >> n;
	LinkedList list;
	for (int i = 0; i < n; i++  ){
		string op;
		cin >> op;
		if (op == "insert"){
			int p, x;
			cin >> p >> x;
			list.insert(p, x);
		}else if (op == "delete"){
			int p;
			cin >> p;
			list.remove(p);

		}
	}
	list.printList();
	return 0;
}
