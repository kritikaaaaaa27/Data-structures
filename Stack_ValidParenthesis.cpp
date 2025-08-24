#include <iostream>
using namespace std;
int s=10;
class Stack{
    public:
    int arr[10];
    int top;
    Stack(){
    top=-1;
    }
    bool IsEmpty(){
    if(top==-1) return true;
    else return false;
    }
    bool IsFull(){
    if(top==(s-1)) return true;
    else return false;
    }
    void Push(int a){
    if(!IsFull()){
    top++;
    arr[top]=a;
    }
    else cout<<"Stack is full";
    }
    int Pop(){
    if(!IsEmpty()){
    int temp=arr[top];
    top--;
    return top;
        }
    else{
        return 2;
        }
    }
    int peek(){
    return arr[top];
    }
};
int main() {
    Stack S;
    S.Push(20);
    S.Push(11);
    S.Pop();
    cout<<S.peek();
    return 0;
}






//VALID PARENTHESIS
#include <iostream>
#include <string>
using namespace std;
int s = 10;

class Stack {
public:
    char arr[10];
    int top;
    Stack() {
        top = -1;
    }
    bool IsEmpty() {
        return top == -1;
    }
    bool IsFull() {
        return top == (s - 1);
    }
    void Push(char a) {
        if (!IsFull()) {
            top++;
            arr[top] = a;
        } else {
            cout << "Stack is full";
        }
    }
    char Pop() {
        if (!IsEmpty()) {
            char temp = arr[top];
            top--;
            return temp;
        } else {
            return '0';
        }
    }
    char peek() {
        return arr[top];
    }
    bool IsValid(string st) {
        for (char ch : st) {
            if (ch == '(' || ch == '[' || ch == '{') {
                Push(ch);
            } else if (ch == ')' || ch == ']' || ch == '}') {
                if (IsEmpty()) return false;
                char top1 = Pop();
                if ((top1 == '(' && ch != ')') ||(top1 == '[' && ch != ']') ||(top1 == '{' && ch != '}')) {
                    return false;
                }
            }
        }
        return IsEmpty();
    }
};
int main() {
    Stack S;
    string st;
    cout << "Enter a string: ";
    cin >> st;

    if (S.IsValid(st))
        cout << "Valid\n";
    else
        cout << "Invalid\n";

    return 0;
}
