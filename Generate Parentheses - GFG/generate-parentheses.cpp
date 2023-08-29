//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses

// https://www.youtube.com/watch?v=WW1rYrR3tTI&ab_channel=CodewithAlisha
class Solution
{
    public:
    void fnc(vector<string>& ans, int n, int open, int close, string curr_str) {
        // Base case
        if (curr_str.size() == n * 2) {
            ans.push_back(curr_str);
            return;
        }
        if (open < n)
            fnc(ans, n, open + 1, close, curr_str + "(");
        if (close < open)
            fnc(ans, n, open, close + 1, curr_str + ")");
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        fnc(ans, n, 1, 0, "(");
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends