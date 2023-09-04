//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int n, int m, vector<int> &g, vector<int> &s) {
        // code here
        // int n=g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        // int m=s.size();
        int i=0;
        int j=0;
        int count=0;
        while(j<n && i<m){
            if((s[i])>=g[j]){
                g[j]=s[i]-g[j];
                count++;
                i++;
                j++;
            }
            else if(s[i]<g[j]){
                i++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends