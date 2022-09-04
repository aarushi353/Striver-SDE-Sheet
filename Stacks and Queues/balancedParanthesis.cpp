class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto p:s){
            if(p=='{' || p =='[' || p=='(') st.push(p);
            else {
                if(st.size()==0) return false;
                char top = st.top();
                if( top == '(' and p == ')' ) st.pop();
                else if( top == '{' and p == '}' ) st.pop();
                else if( top == '[' and p == ']' ) st.pop();
                else return false;
            }
        }
        return st.size()==0;
    }
};