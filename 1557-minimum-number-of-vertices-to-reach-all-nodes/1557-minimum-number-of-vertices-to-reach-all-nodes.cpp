class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);
        for(auto edge:edges){
            visited[edge[1]]=true;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};