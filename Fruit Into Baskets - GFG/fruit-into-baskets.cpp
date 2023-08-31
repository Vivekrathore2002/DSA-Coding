//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// https://www.youtube.com/watch?v=g2teoWNXspI
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int ans = 0;
          map<int,int>mp;
          int i =0 ,j =0,n = fruits.size();
          while(i<n)
          {
            mp[fruits[i]]++;
          while(mp.size()>2)
          {
           if(mp[fruits[j]] == 1)
           {
            mp.erase(fruits[j]);
           }
            else
            {
            mp[fruits[j]]--;
            }
            j++;
          }
           ans = max(i-j+1,ans);
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
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends