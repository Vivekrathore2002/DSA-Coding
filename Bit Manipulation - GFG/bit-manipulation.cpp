//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        //Get bit
        i=i-1;
        int n=1<<i;
        if(n&num){
            cout<<"1 ";
        }else{
            cout<<"0 ";
        }
        //Set bit
        cout<<(num|n)<<" ";
        n=~n;
        cout<<(num&n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends