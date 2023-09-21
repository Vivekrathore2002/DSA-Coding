//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// https://youtu.be/eccAKrmffh8?si=kdBgi8XTWo0CE_j0
// approach 1 : N^2*logn
class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        vector<int> sumStore;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum+=arr[j];
                sumStore.push_back(sum);
            }
        }
        
        // till now the complexity was N^2 now the length is equal to N^2 so,
        // the sorting comlexity will combined (N^2)*(logn)
        sort(sumStore.begin(),sumStore.end());
        return sumStore[sumStore.size()-k];
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends