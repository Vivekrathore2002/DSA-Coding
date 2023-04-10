class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);
        for(int i=0;i<numRows;i++){
            r[i].resize(i+1);
            r[i][0]=r[i][i]=1;
            for(int j=1;j<i;j++){
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
        }
        return r;
        // vector<vector<int>> ans;
        // ans.push_back({1});
        // for(int i = 1; i < numRows; i++){
        //     int n = i+1;
        //     vector<int> temp(n,1);
        //     int cond;
        //     if(n % 2 == 0) cond = n/2;
        //     else cond = (n+1)/2;
        //     for(int j = 1; j < cond; j++){
        //         temp[j] = ans[i-1][j] + ans[i-1][j-1];
        //         temp[i - j] = temp[j];
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
    }
};