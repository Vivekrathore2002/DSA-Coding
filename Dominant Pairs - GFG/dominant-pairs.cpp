//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// class Solution{
// public:
//     int dominantPairs(int n,vector<int> &arr){
//         // //first solution where almost all test case passed but not optimull
//         // int count=0;
//         // for(int i = 0; i < n; i++){
//         //     for(int j=i+1;j<n;j++){
//         //         if(i<n/2 && n/2<=j && arr[i]>=5*arr[j]){
//         //             count++;
//         //         }
//         //     }
//         // }
//         // return count;
//         //Optimized code now
        
//     }  
// };
class Solution{
public:
// first Optimized code now
    // int dominantPairs(int n, vector<int>& arr){
    //     int count = 0;
    //     int maxElementIndex = 0;
    //     for(int i = 1; i < n; i++){
    //         if(arr[i] >= arr[maxElementIndex]){
    //             maxElementIndex = i;
    //         }
    //         else if(maxElementIndex < n/2 && arr[i] >= arr[maxElementIndex]/5){
    //             count++;
    //         }
    //     }
    //     return count;
    //2nd optimized code
     int binarySearch(vector<int> &arr,int key,int n){
        int low = n/2, high = n-1, mid, index=-1;
        while(low<=high){
            mid = (low+high)/2;
            if(5*arr[mid]<=key){
                index=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return index;
    }
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        sort(arr.begin()+n/2,arr.end());
        int ans=0;
        for(int i=0;i<n/2;i++){
            int index = binarySearch(arr,arr[i],n);
            if(index!=-1)ans+=(index-n/2)+1;
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends