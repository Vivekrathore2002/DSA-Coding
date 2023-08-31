//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int ans = 0;
        int flip = 0;
        int i = 0;
        int j = 0;
        // int n = nums.size();
        while (i < n) {
            if (nums[i] == 0) {
                flip++;
            }
            while (flip > k) {
                if (nums[j] == 0)
                    flip--;
                j++;
            }
            ans = max(ans, i - j + 1);
            i++;
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
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends