//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// https://www.youtube.com/watch?v=s4t3YDw4RcY
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int N)
    {
        // Your logic here
        int ans = 0,i=1,n=N;
        while(n!=0){
            int temp = (N+1)/(i*2);
            ans+=temp*i;
            temp = (N+1)/i;
            if(temp%2==1)ans+=(N+1)%i;
            i*=2;
            n>>=1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends