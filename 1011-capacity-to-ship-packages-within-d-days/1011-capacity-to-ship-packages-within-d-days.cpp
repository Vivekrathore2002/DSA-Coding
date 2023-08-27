// youtube.com/watch?v=MG-Ac4TAvTY
class Solution {
public:
    int findDays(vector<int>& weights,int cap){
        int n=weights.size();
        int days=1;
        int load=0;
        for(int i=0;i<n;i++){
            if(weights[i]+load>cap){
                days+=1;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int d) {
        int n=weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid = low+(high-low)/2;
            int numberOfDays = findDays(weights,mid);
            if(numberOfDays<=d){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};