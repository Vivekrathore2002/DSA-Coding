class Solution {
public:
bool can_do(string& s,string& sub){
    int j=0;
    int n=s.size();
    int m=sub.size();
    for(int i=0;i<n and j<m; i++){
        if(sub[j]==s[i]){
            j++;
        }
      
    }
      return (j==m);
}


    int maximumRemovals(string s, string p, vector<int>& r) {
        int start=0;
        int end =r.size();
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            string temp=s;
            for(int i=0;i<mid;i++){
                temp[r[i]] = 'A';
            }
            if(can_do(temp , p)){
                ans=mid;
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return ans;
    }
};