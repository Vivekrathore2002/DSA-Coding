class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
         vector<int>money;
        for(int i=0;i<accounts.size();i++){
            int wealth=0;
            for(int j=0;j<accounts[0].size();j++){
                wealth+=accounts[i][j];
            }
            money.push_back(wealth);
        }
        sort(money.begin(),money.end());
        return(money[money.size()-1]);
    }
};