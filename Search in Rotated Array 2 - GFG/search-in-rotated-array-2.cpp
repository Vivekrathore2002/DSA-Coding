//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int Key) {
    int s = 0;
    int e = N - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (A[mid] == Key) {
            return true;
        }
        // Handle duplicates at the boundaries
        if (A[mid] == A[s] && A[mid] == A[e]) {
            s++;
            e--;
        }
        else if (A[mid] <= A[e]) { // Right half is sorted
            if (A[mid] < Key && Key <= A[e]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        else { // Left half is sorted
            if (A[s] <= Key && Key < A[mid]) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
    }
    return false;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends