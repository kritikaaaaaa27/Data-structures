#include <bits/stdc++.h>
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
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}

void Postfix(string exp) {
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            cout << c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (st[top] != '(') {
                cout << pop();
            }
            pop();
        }
        else {
            while (top != -1 && prec(st[top]) >= prec(c)) {
                cout << pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        cout << pop();
    }
}

void Prefix(string exp) {
    reverse(exp.begin(), exp.end());
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
    string result = "";
    top = -1;
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && st[top] != '(') {
                result += pop();
            }
            pop();
        }
        else {
            while (top != -1 && prec(st[top]) >= prec(c)) {
                result += pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        result += pop();
    }
    reverse(result.begin(), result.end());

    cout << result;
}

int main() {
    string exp;
    cout << "Enter: ";
    cin >> exp;

    cout << "Postfix: ";
    Postfix(exp);
    cout << endl;

    cout << "Prefix: ";
    Prefix(exp);
    cout << endl;

    return 0;
}
