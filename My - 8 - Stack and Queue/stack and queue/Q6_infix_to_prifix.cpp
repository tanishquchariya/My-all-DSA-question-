// C++ program to convert infix to prefix
#include <bits/stdc++.h>
using namespace std;

// Check if character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || 
    ch == '*' || ch == '/' || ch == '^');
}

// Get precedence of operators
int priority(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}

// Convert infix expression to postfix notation
string convertInfixToPostfix(string s) {
    stack<char> st;
    string ans;

    for (int i = 0; i < s.size(); i++) {
        if (isalnum(s[i])) {
          // of if(isalpha(s[i]) || isdigit(s[i]))
            ans += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

// Convert infix expression to prefix notation
string convertToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string postfix = convertInfixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    // string s = "(p+q)*(c-d)";
    // string s = "(A+B*C)";
    cout << convertToPrefix(s) << endl;
    return 0;
}