//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        unordered_map<char,int> mp1;
        int n1=a.length();
        int n2=b.length();
        if(n1!=n2){
            return false;
        }
        for(int i=0;i<n1;i++){
            mp1[a[i]]++;
        }
        for(int i=0;i<n2;i++){
            mp1[b[i]]--;
        }
        for(auto x:mp1){
            if(x.second!=0){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends