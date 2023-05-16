class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // if(ceil(hour)<dist.size()){ ////
        //     return -1;
        // }
        int s=1;
        int e=1e7;
        int ans=-1;
        int n=dist.size();
        while(s<=e){
            int m=s+(e-s)/2;
            double hr=0;
            for(int i=0;i<n;i++){
                if(i<n-1){////
                hr+=ceil((double)dist[i]/m);
                }
                else{
                    hr+=((double)dist[i]/m);
                }
            }
            if(hr<=hour){
                ans=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return ans;
    }
};