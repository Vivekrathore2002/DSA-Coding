//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int c[3] ={},ans=0,i=0;
        int n = s.length();
        for(int j=0;j<n;j++) 
        {
            c[s[j] - 'a']++;
            while (c[0] && c[1] && c[2])
            c[s[i++] - 'a']--;
            ans+=i;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends