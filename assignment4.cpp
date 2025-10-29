#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c=='^') return 3;
    if (c=='*' || c=='/') return 2;
    if (c=='+' || c=='-') return 1;
    return -1;
}

// Infix to Postfix
string infixToPostfix(string s) {
    stack<char> st;
    string res="";
    for (char c: s) {
        if (isdigit(c)) res += c;              // operand
        else if (c=='(') st.push(c);
        else if (c==')') {
            while (!st.empty() && st.top()!='(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else {                                // operator
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                if (c=='^' && st.top()=='^') break; // right assoc
                res += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res += st.top(); st.pop();
        }
    return res;
}

// Infix to Prefix
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for (char &c: s) {
        if (c=='(') c=')';
        else if (c==')') c='(';
    }
    string post = infixToPostfix(s);
    reverse(post.begin(), post.end());
    return post;
}

// Evaluate Postfix
int evalPostfix(string s) {
    stack<int> st;
    for (char c: s) {
        if (isdigit(c)) st.push(c-'0');
        else {
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            if (c=='+') st.push(a+b);
            else if (c=='-') st.push(a-b);
            else if (c=='*') st.push(a*b);
            else if (c=='/') st.push(a/b);
            else if (c=='^') st.push(pow(a,b));
        }
    }
    return st.top();//this is the final evaluation of the postfix expression
}

// Evaluate Prefix
int evalPrefix(string s) {
    stack<int> st;
    for (int i=s.size()-1; i>=0; i--) {
        char c = s[i];
        if (isdigit(c)) st.push(c-'0');
        else {
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            if (c=='+') st.push(a+b);
            else if (c=='-') st.push(a-b);
            else if (c=='*') st.push(a*b);
            else if (c=='/') st.push(a/b);
            else if (c=='^') st.push(pow(a,b));
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix (single digit operands): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix  = infixToPrefix(infix);

    cout << "\nInfix   : " << infix;
    cout << "\nPostfix : " << postfix;
    cout << "\nPrefix  : " << prefix;
    cout << "\nPostfix Evaluation = " << evalPostfix(postfix);
    cout << "\nPrefix Evaluation  = " << evalPrefix(prefix) << endl;
}
