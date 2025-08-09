#include <bits/stdc++.h>
using namespace std;
bool isoperand(char ch){
    return (ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='1' && ch<='9');
}
string prefixToInfix(string prefix) {
    // Write your code here.
    stack<string>st;
    for(int i =prefix.size()-1; i>=0; i--){
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

            st.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }
        return st.top();
}
// Driver code
int main()
{
    string exp = "+*abc";
    cout << prefixToInfix(exp);
    return 0;
}