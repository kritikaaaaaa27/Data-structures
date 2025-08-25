#include <iostream>
using namespace std;

char st[100];
int top = -1;

void push(char c) {
    top++;
    st[top] = c;
}

char pop() {
    char c = st[top];
    top--;
    return c;
}

int prec(char c) {
    if (c=='+' || c=='-') return 1;
    if (c=='*' || c=='/') return 2;
    if (c=='^') return 3;
    return -1;
}

void Postfix(string exp) {
    for (int i=0; i<exp.length(); i++) {
        char c = exp[i];
        if ((c>='a'&&c<='z') || (c>='A'&&c<='Z') || (c>='0'&&c<='9')) {
            cout << c;
        }
        else if (c=='(') {
            push(c);
        }
        else if (c==')') {
            while (st[top] != '(') {
                cout << pop();
            }
            pop();
        }
        else { // operator
            while (top!=-1 && prec(st[top]) >= prec(c)) {
                cout << pop();
            }
            push(c);
        }
    }
    while (top!=-1) {
        cout << pop();
    }
}
int main() {
    string exp;
    cout << "Enter: ";
    cin >> exp;
    cout << "Postfix: ";
    Postfix(exp);
    cout << endl;
}
