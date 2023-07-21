//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int missingNumber(vector<int>& array, int n) {
        long long totalSum = (n * (n + 1)) / 2; // Sum of first n natural numbers
        long long arraySum = accumulate(array.begin(), array.end(), 0LL); // Sum of elements in the array
        return static_cast<int>(totalSum - arraySum);
    }
};







//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends