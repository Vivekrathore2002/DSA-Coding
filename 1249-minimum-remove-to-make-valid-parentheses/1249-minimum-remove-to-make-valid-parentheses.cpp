class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        }
        else if (s[i] == ')') {
            if (!st.empty()) {
                st.pop();
            } else {
                s[i] = '*'; // Mark invalid closing parentheses for removal
            }
        }
    }
    while (!st.empty()) {
        int idx = st.top();
        st.pop();
        s[idx] = '*'; // Mark unclosed opening parentheses for removal
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end()); // Remove marked parentheses
    return s;
    }
};