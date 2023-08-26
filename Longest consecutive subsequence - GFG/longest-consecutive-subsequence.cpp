//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// https://www.youtube.com/watch?v=pLzOp2_Y9Vk
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        set<int> s;
        for (int i = 0; i < N; i++) {
            s.insert(arr[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int current_element = arr[i];
            int previous_element = current_element - 1;
            int count = 0;
            
            if (s.find(previous_element) == s.end()) {
                while (s.find(current_element) != s.end()) {
                    current_element++;
                    count++;
                }
            }
            
            ans = max(ans, count);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends