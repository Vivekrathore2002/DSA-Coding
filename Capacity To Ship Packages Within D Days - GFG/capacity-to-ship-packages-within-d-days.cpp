//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// youtube.com/watch?v=MG-Ac4TAvTY
class Solution {
  public:
  int findDays(int arr[],int cap,int n){
      int days=1;
      int load=0;
      for(int i=0;i<n;i++){
          if(arr[i]+load>cap){
              days+=1;
              load = arr[i];
          }
          else{
              load+=arr[i];
          }
      }
      return days;
  }
    int leastWeightCapacity(int arr[], int n, int d) {
        
        //finding the lowest element which is max of the array since divisor can not be lesser than that
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]);
        }
        int low = mx;
        //finding sum which will be working as high
        // int low = *max_element(arr.begin(),arr.end());
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int high = sum;
        while(low<=high){
            int mid = low+(high-low)/2;
            int numberOfDays = findDays(arr,mid,n);
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends