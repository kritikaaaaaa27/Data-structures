#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class Stack {
    Node* top;
public:
    Stack() {
        top = NULL;
    }
    void Push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    void Pop() {
        if (top == NULL) {
            cout << "empty\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    void Display() {
        if (top == NULL) {
            cout << "Stack empty\n";
            return;
        }
        cout << "Stack: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Display();
    cout<<"After popping\n";
    s.Pop();
    s.Display();
    return 0;
}
