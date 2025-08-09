// prefix to postfix conversion
#include <bits/stdc++.h>
using namespace std;
bool isoperand(char ch){
    return (ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='1' && ch<='9');
}
string prefixToPostfix(string prefix) {
    // Write your code here.
    stack<string>st;
    for(int i= prefix.size()-1; i>=0; i--){
        if(isoperand(prefix[i])){
            string op = "";
            //(or) string op(1,postfix[i]);
            op += prefix[i];
            st.push(op);
        }
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            st.push(op1 + op2 + prefix[i]);
        }
    }
        return st.top();
}
// Driver code
int main()
{
    // string exp = "+*abc";
    string exp = "/-AB*+DEF";
    cout << prefixToPostfix(exp);
    return 0;
}