// postfix to prefix conversion
#include <bits/stdc++.h>
using namespace std;
bool isoperand(char ch){
    return (ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='1' && ch<='9');
}
string postfixToPrefix(string postfix) {
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

            st.push(postfix[i] + op2 + op1);
        }
    }
        return st.top();
}
// Driver code
int main()
{
    string exp = "ab*c+";
    cout << postfixToPrefix(exp);
    return 0;
}