//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int finLength(int N, vector<int>& color, vector<int>& radius) {
        // // 1st solution by chatgpt
        // stack<pair<int, int>> stk; // pair of (color, radius)
        // for (int i = 0; i < N; i++) {
        //     if (!stk.empty() && stk.top().first == color[i] && stk.top().second == radius[i]) {
        //         stk.pop(); // remove the previous ball if it is the same as the current one
        //     } else {
        //         stk.push({color[i], radius[i]});
        //     }
        // }
        // return stk.size();
        // 2nd question by main easy concept
        stack<int> st;
        for(int i=0;i<N;i++){
            if(st.size()){
                int index = st.top();
                if(color[index]==color[i] && radius[index]==radius[i])st.pop();
                else st.push(i);
            }
            else st.push(i);
        }
        return st.size();
    }
};



//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends