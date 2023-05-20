class Solution {
public:

    bool dfs(string source, string dest, unordered_map<string, bool> &vis, unordered_map<string, vector<pair<string, double>>> &mp, double temp, double &val){

        vis[source] = true;

        if(source == dest){
            val = temp;
            return true;
        }

        string neigh;
        double ratio;
        for(int i=0; i<mp[source].size(); i++){
            neigh = mp[source][i].first;
            ratio = mp[source][i].second;
            if(!vis[neigh]){
                if(dfs(neigh, dest, vis, mp, temp*ratio, val))return true;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = values.size();
        unordered_map<string, vector<pair<string, double>>> mp;
        for(int i=0; i<n; i++){
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        int nq = queries.size();
        vector<double> rv;

        for(int i=0; i<nq; i++){
            unordered_map<string, bool> vis;
            double val = -1.0, temp = 1.0;
            if(mp.find(queries[i][0]) != mp.end())
                dfs(queries[i][0], queries[i][1], vis, mp, temp, val);
         
            rv.push_back(val);
        }
        return rv;
    }
};