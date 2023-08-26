//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
// https://www.youtube.com/watch?v=xvNwoz-ufXA
class Solution{
public:
    int findSubArraySum(int arr[], int n, int k)
    {
        // Edge case: Empty array or single element
        if (n == 0 || (n == 1 && arr[0] != k)) {
            return 0;
        }
        
        unordered_map<int, int> mpp; // Use unordered_map for efficiency
        int preSum = 0, cnt = 0;

        mpp[0] = 1; // Setting 0 in the map.
        for (int i = 0; i < n; i++) {
            preSum += arr[i];
            
            int remove = preSum - k;
            
            // Check if remove exists in the map
            if (mpp.find(remove) != mpp.end()) {
                cnt += mpp[remove];
            }
            
            mpp[preSum] += 1;
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends