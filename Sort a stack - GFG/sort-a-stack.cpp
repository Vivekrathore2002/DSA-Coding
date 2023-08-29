//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */


// void SortedStack :: sort()
// {
   //Your code here
//   1st approach using pririty queue
    // priority_queue<int, vector<int>, greater<int>> minH;
    //     while(!s.empty())
    //     {
    //         minH.push(s.top());
    //         s.pop();
    //     }
    //     while(!minH.empty())
    //     {
    //         s.push(minH.top());
    //         minH.pop();
    //     }
    
    
    
// }

// 2nd approach by love babbar

void sortedInsert(stack<int> &s, int num) {
    // Base case
    if (s.empty() || num > s.top()) {
        s.push(num);
        return;
    }
    
    // Pop elements until the correct position is found
    int temp = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(temp);
}

void SortedStack::sort() {
    if (s.empty()) {
        return;
    }
    
    int num = s.top();
    s.pop();
    
    // Recursively sort the remaining stack
    sort();
    
    // Insert the popped element at the correct position
    sortedInsert(s, num);
}
