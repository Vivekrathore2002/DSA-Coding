class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // push a dummy index onto the stack to handle the case where the first character is a closing parenthesis
        int maxLength = 0;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else {
                if(!st.empty()){
                    st.pop();
                    if(!st.empty()){
                        int length = i - st.top();
                        maxLength = max(maxLength, length);
                    }
                    else {
                        st.push(i); // push the current index onto the stack to handle the case where there are more closing parentheses than opening parentheses
                    }
                }
            }
        }
        return maxLength;
    }
};
