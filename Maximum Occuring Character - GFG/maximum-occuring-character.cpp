//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        //create an array of count of characters;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            //lowercase
            int number = 0;
            number = ch-'a'; //Gives the 0 for a,1 for b...etc
            arr[number]++;//increase the corresposing number of perticular char
        }
        //now find maximum occ of a char
        int maxi = -1;
        int ans=0;
        for(int i=0;i<26;i++){
            if(maxi<arr[i]){
                ans=i;
                maxi=arr[i];
            }
        }
        return 'a'+ans;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends