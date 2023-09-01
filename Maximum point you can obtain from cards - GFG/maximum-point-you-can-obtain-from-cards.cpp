//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// https://www.youtube.com/watch?v=GIO9YRFmMXA/
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int n, int k) {
        vector<int> sum(cardPoints.size(),0);
        long long Sum=0;
        for(int i=0;i<cardPoints.size();i++){
            Sum+=cardPoints[i];
            sum[i]=Sum;
        }
        if(cardPoints.size()==k)
        return Sum;
        
        long long score =0;
        long long ans=0;
        for(int i=0;i<=k;i++){
            int j = i + cardPoints.size()-k-1;
            if(i==0){
                ans=sum[j];
            }
            else{
                ans=sum[j] - sum[i-1];
            }
            score = max(score,Sum-ans);
        }
        return score;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends