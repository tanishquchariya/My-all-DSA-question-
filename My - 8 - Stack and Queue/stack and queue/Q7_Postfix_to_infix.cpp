#include <bits/stdc++.h>
using namespace std;
bool isoperand(char ch){
    return (ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='1' && ch<='9');
}
string postToInfix(string postfix) {
    // Write your code here.
    stack<string>st;
    for(int i =0; i<postfix.size(); i++){
        if(isoperand(postfix[i])){
            string op = "";
            //(or) string op(1,postfix[i]);
            op += postfix[i];
            st.push(op);
        }
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            st.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }
        return st.top();
}
// Driver code
int main()
{
    string exp = "ab*c+";
    cout << postToInfix(exp);
    return 0;
}

// // postfix to infix conversion in C++
// #include <bits/stdc++.h>
// using namespace std;

// bool isOperand(char x)
// {
//    return (x >= 'a' && x <= 'z') ||
//           (x >= 'A' && x <= 'Z');
// }

// // Get Infix for a given postfix
// // expression
// string getInfix(string exp)
// {
//     stack<string> s;

//     for (int i=0; exp[i]!='\0'; i++)
//     {
//         // Push operands
//         if (isOperand(exp[i]))
//         {
//            string op(1, exp[i]);
//            s.push(op);
//         }

//         // We assume that input is
//         // a valid postfix and expect
//         // an operator.
//         else
//         {
//             string op1 = s.top();
//             s.pop();
//             string op2 = s.top();
//             s.pop();
//             s.push("(" + op2 + exp[i] +
//                    op1 + ")");
//         }
//     }

//     // There must be a single element
//     // in stack now which is the required
//     // infix.
//     return s.top();
// }
