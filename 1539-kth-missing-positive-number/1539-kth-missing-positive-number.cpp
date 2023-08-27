// https://www.youtube.com/watch?v=uZ0N_hZpyps
// we can do it less than O(n) which will be binary search O(logn)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
       int low=0;
       int high=n-1;
       while(low<=high){
           int mid = low+(high-low)/2;
           int missing = arr[mid] - (mid+1);
           if(missing<k){
               low=mid+1;
           }
           else{
               high=mid-1;
           }
       }
       return k+high+1;
    }
};