//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> mm;
		    queue<char> q;
		    string ans="";
		    for(int i=0;i<A.length();i++){
		        mm[A[i]]++;
		        if(mm[A[i]]==1)q.push(A[i]);
		        while(q.size()!=0 && mm[q.front()]>1)q.pop();
		        if(q.size()==0)ans+='#';
		        else ans+=q.front();
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends