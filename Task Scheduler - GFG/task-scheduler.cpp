//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // int N=tasks.size();
        unordered_map<char,int> mp;
        int count=0;
        for(auto e:tasks){
            mp[e]++;
            count=max(count,mp[e]);
        }
        int ans=(count-1)*(K+1);
        for(auto e:mp){
            if(e.second==count){
                ans++;
            }
        }
        return max(N,ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends