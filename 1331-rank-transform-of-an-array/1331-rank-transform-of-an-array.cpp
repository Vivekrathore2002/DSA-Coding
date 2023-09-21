class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        unordered_map<int,int> mp;
        int rank=1;
        int i=0;
        while(pq.size()){
            int num = pq.top();
            pq.pop();
            if(mp.find(num)==mp.end()){
                mp[num]=rank;
                rank++;
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};