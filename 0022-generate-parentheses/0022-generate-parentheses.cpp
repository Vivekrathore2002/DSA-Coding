// https://www.youtube.com/watch?v=WW1rYrR3tTI&ab_channel=CodewithAlisha
// && Chatgpt
// In the generateParenthesis function, the initial call to fnc passes 0 for both open and close arguments. However, it should be 1 for the open argument because the first character in the generated string is an opening parenthesis.
class Solution {
public:
    void fnc(vector<string>& ans, int n, int open, int close, string curr_str) {
        // Base case
        if (curr_str.size() == n * 2) {
            ans.push_back(curr_str);
            return;
        }
        if (open < n)
            fnc(ans, n, open + 1, close, curr_str + "(");
        if (close < open)
            fnc(ans, n, open, close + 1, curr_str + ")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fnc(ans, n, 1, 0, "(");
        return ans;
    }
};
