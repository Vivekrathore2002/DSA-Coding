// https://www.youtube.com/watch?v=fFH4H4oXEOU
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char> st;
        for(auto x:s){
            if(x=='('){
                if(st.size()>0){
                    ans.push_back(x);
                }
                st.push(x);
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};