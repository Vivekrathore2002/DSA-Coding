//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> find(int arr[], int n, int x)
{
    vector<int> ans(2, -1); // Initialize ans with -1, representing not found
    int i = 0;
    // Find the first occurrence of x
    while (i < n) {
        if (arr[i] == x) {
            ans[0] = i;
            break;
        }
        i++;
    }
    // Find the last occurrence of x
    while (i < n) {
        if (arr[i] == x) {
            ans[1] = i;
        }
        i++;
    }
    return ans;
}
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends