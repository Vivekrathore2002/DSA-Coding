// https://www.youtube.com/watch?v=ZZddzQDilDo
// we will be using set to store the elements in sorted,ascending order(default in set)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> s;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j =0;j<m;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            s.insert({count,i}); //stored the count of 1 and the 
        }
        vector<int> ans;
        for(auto x=begin(s);k>0;k--,x++){
            ans.push_back(x->second);
        }
        return ans;
    }
};