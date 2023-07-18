//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length();
		    vector<int> nichli(n+1),cur(n+1);
		    for(int i=n;i>=0;i--){
		        for(int j=n;j>=0;j--){
		            if(i==n or j==n)cur[j]=0;
		            else if(str[i]==str[j] and i!=j){
		                cur[j]=1+nichli[j+1];
		            }
		            else cur[j]=max(nichli[j],cur[j+1]);
		        }
		        nichli=cur;
		    }
		    return nichli[0];
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends