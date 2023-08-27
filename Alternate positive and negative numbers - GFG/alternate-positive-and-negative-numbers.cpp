//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int A[], int n) {
	    vector<int> pos;
          vector<int> neg;
          
          // Segregate the array into positives and negatives.
          for(int i=0;i<n;i++){
              
              if(A[i]>=0) pos.push_back(A[i]);
              else neg.push_back(A[i]);
          }
          
          // If positives are lesser than the negatives.
          if(pos.size() < neg.size()){
              
            // First, fill array alternatively till the point 
            // where positives and negatives ar equal in number.
            for(int i=0;i<pos.size();i++){
              
              A[2*i] = pos[i];
              A[2*i+1] = neg[i];
            }
            
            // Fill the remaining negatives at the end of the array.
            int index = pos.size()*2;
            for(int i = pos.size();i<neg.size();i++){
                
                A[index] = neg[i];
                index++;
            }
          }
          
          // If negatives are lesser than the positives.
          else{
              
              // First, fill array alternatively till the point 
              // where positives and negatives ar equal in number.
              for(int i=0;i<neg.size();i++){
              
              A[2*i] = pos[i];
              A[2*i+1] = neg[i];
          }
            
            // Fill the remaining positives at the end of the array.
            int index = neg.size()*2;
            for(int i = neg.size();i<pos.size();i++){
                
                A[index] = pos[i];
                index++;
            }
          }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends