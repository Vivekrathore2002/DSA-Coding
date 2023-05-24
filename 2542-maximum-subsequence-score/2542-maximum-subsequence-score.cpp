class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums1[i],nums2[i]});
        }
        // sorting and reversing the vector in terms of nums1
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        // to store final answer
        long long ans=-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // sum to track the total sum of elemnts from nums1 that we have picked till now
        long long sum=0; 
        for(int i=0;i<n;i++)
        {
           // push the pair after reversing it as we need the minimum of nums2 on the top
           pq.push({v[i].second,v[i].first});
           sum+=v[i].first;
           // when we have selected k elements check if the current case can be our answer or not
           if(pq.size()==k)
           {
                int s=pq.top().second;
                int m=pq.top().first;
                pq.pop();
                if(sum*1LL*m>ans)
                 ans=sum*1LL*m;
                sum-=s;
           }   
        }
       return ans;
    }
};