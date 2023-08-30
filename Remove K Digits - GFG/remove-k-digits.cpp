//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";
        stack<char>s;
        for(int i=0; i<num.size();i++){   
            if(s.empty()) s.push(num[i]);    
            else{
                while(!s.empty() && s.top() > num[i] && k>0){     
                    s.pop();
                    k--;
                }
                s.push(num[i]);
            }
        }
        while(k>0){
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        string ans; 
        while(!s.empty()){
            ans = s.top()+ans;    
            s.pop();
        }
        int i=0;
        while(ans[i] == '0'){
            i++;
        }
        return (ans.substr(i) == "")? "0": ans.substr(i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends