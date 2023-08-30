class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) {
            return "0";
        }
        
        stack<char> s;
        for (int i = 0; i < num.size(); i++) {
            while (!s.empty() && s.top() > num[i] && k > 0) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        
        while (k > 0) {
            s.pop();
            k--;
        }
        
        string ans = "";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        
        // Reverse the answer string
        reverse(ans.begin(), ans.end());
        
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        
        return (i == ans.size()) ? "0" : ans.substr(i);
    }
};
