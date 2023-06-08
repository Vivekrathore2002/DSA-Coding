//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> fact(n+1,1);
        for(int i=1;i<=n;i++)fact[i]=i*fact[i-1];
        vector<bool> vis(n+1,false);
        string ans="";
        int i=n;
        while(ans.length()!=n){
            int row = k/fact[i-1];
            if(k%fact[i-1])row++;
            for(int j=1;j<=n;j++){
                if(vis[j]==false){
                    row--;
                }
                if(row==0){
                    vis[j]=true;
                    ans+=(j+'0');
                    break;
                }
            }
            k = k%fact[i-1];
            if(k==0)k=fact[i-1];
            i--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends