class Solution {
public:
    long mostPoints(vector<vector<int>>& questions) {
        vector<long> dp(questions.size());

        for(int i=questions.size()-1; i>=0; i--){
            int furtureReachIndex = i + questions[i][1] + 1;
            if(furtureReachIndex < questions.size()){
                dp[i] = dp[furtureReachIndex] + questions[i][0];
            } else {
                dp[i] = questions[i][0];
            }

            if(i < questions.size()-1) {
                // skip the ith index
                dp[i] = max(dp[i+1], dp[i]);
            }
        }
        return dp[0];
    }
};