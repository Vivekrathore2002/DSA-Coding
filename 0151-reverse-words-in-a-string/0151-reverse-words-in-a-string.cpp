//Me with little help of chatgpt
class Solution {
public:
    string reverseWords(string s) {
        string output;
        int n = s.size();
        stack<char> st;
        bool wordStarted = false; // Flag to track if a word has started
        for(int i = n - 1; i >= 0; i--){
            if(s[i] != ' ') {
                st.push(s[i]);
                wordStarted = true;
            } else {
                if(wordStarted) { // Add this condition to exclude leading and trailing spaces
                    while(!st.empty()){
                        output += st.top();
                        st.pop();
                    }
                    output += ' '; // Add space after each word
                    wordStarted = false; // Reset the flag
                }
            }
        }
        while(!st.empty()){
            output += st.top();
            st.pop();
        }
        
        // Remove trailing space
        if (!output.empty() && output.back() == ' ') {
            output.pop_back();
        }
        
        return output;
    }
};
