class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        unordered_set<int>n;
        for(int i=0;i<arr.size();i++)
        {
            n.insert(m[arr[i]]);

        }
        if(m.size()==n.size())
        {
            return true;
        }
      return false; 
        
    }
};