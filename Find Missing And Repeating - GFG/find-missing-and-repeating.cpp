//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends



class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        // int n = v.size();
        vector<int> ans(2);
        
        for (int i = 0; i < n; ++i) {
            while (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i != arr[i] - 1) {
                ans[0] = arr[i];
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends