//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//1st approach passing 912/1012 test cases and giving TLE after that since q1==q2 comparision takes extra time
class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if (s1.size() != s2.size())
        return false;
        queue<char> q1;
        queue<char> q2;
        for(int i=0;i<s1.size();i++){
            q1.push(s1[i]);
        }
        for(int i=0;i<s2.size();i++){
            q2.push(s2[i]);
        }
        int k=0;
        while(k<q2.size()){
            int q=q2.front();
            q2.pop();
            q2.push(q);
            if(q1==q2)
            return true;
            k++;
        }
        return false;
    }
};

// class Solution
// {
//     public:
//     //Function to check if two strings are rotations of each other or not.
//     bool areRotations(string s1,string s2)
//     {
        
//     }
// };

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends