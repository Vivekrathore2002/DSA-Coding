//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string output;
        int n = S.size();
        stack<char> st;
        bool wordStarted = false; // Flag to track if a word has started
        for(int i = n - 1; i >= 0; i--){
            if(S[i] != '.') {
                st.push(S[i]);
                wordStarted = true;
            } else {
                if(wordStarted) { // Add this condition to exclude leading and trailing spaces
                    while(!st.empty()){
                        output += st.top();
                        st.pop();
                    }
                    output += '.'; // Add space after each word
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

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends