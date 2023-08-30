//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        // int n=asteroids.size();
        stack<int> st;
       for(auto x : asteroids){
           if(x>0){
               st.push(x);
           }
           else{
               while(st.size() && st.top()>0 && st.top()<abs(x))
               {
                   st.pop();
               }
               if(st.empty()){
                   st.push(x);
               }
               else{
                   if(st.top()>0 && st.top()==abs(x)){
                       st.pop();
                   }
                   else if(st.top()<0){
                       st.push(x);
                   }
               }
           }
       }
       vector<int> ans;
       while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
       }
       reverse(ans.begin(),ans.end());
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends