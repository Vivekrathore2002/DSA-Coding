class Solution {
public:
    int DP[10001]; //GLOBAL

    int solve(int amt,vector<int> &coins){ //Helper Function
        if(amt==0)
            return 0;
    
        if(DP[amt]!=-1){
            return DP[amt];
        }
        int ans = 1e9;
        for(auto i:coins){
            if(amt>=i)
                ans = min(ans,solve(amt-i,coins)+1);
        }
        DP[amt] = ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(DP,-1,sizeof(DP));
        int ans = solve(amount,coins);
        if(ans>=1e9){
            ans = -1;
        }
        return ans;
    }
};