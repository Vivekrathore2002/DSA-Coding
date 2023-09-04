class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1=g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n2=s.size();
        int i=0;
        int j=0;
        int count=0;
        while(j<n1 && i<n2){
            if((s[i])>=g[j]){
                g[j]=s[i]-g[j];
                count++;
                i++;
                j++;
            }
            else if(s[i]<g[j]){
                i++;
            }
        }
        return count;
    }
};