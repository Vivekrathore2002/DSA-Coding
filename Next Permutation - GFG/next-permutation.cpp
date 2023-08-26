//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// https://www.youtube.com/watch?v=ho4gTCr0QSk
class Solution {
public:
    vector<int> nextPermutation(int n, vector<int> nums) {
        int infpt = -1;  // Initialize to -1 to detect if we found a valid insertion point

        // Find the index of the first element that breaks the descending order
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                infpt = i;
                break;
            }
        }
        if (infpt == -1) {
            reverse(nums.begin(), nums.end());  // Already in the largest permutation, reverse it
        } 
        else {
            int toswap = nums[infpt];

            // Find the smallest number to the right of nums[infpt] that is greater than nums[infpt]
            int minDiff = INT_MAX;
            int minDiffIdx = infpt + 1;

            for (int j = infpt + 1; j < n; j++) {
                if (nums[j] > toswap && nums[j] - toswap < minDiff) {
                    minDiff = nums[j] - toswap;
                    minDiffIdx = j;
                }
            }
            // Swap the elements at infpt and minDiffIdx
            swap(nums[infpt], nums[minDiffIdx]);
            // Reverse the sub-array to the right of infpt to get the smallest permutation
            reverse(nums.begin() + infpt + 1, nums.end());
        }
        return nums;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends